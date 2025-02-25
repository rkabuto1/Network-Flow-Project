#include "dinic.h"
#include <unistd.h>

int main(int argc, const char **argv) {
  vli geeksforgeeks = {{{1,16},{2,13}}, {{2,10},{3,12}}, {{1,4},{4,14}}, {{2,9},{5,20}}, {{3,7},{5,4}}, {}};
  // pair<int,int> -> (node, capacity), adjacency list

  hc::time_point start = hc::now();
  int maxFlow = DinicsAlgorithm(geeksforgeeks);
  hc::time_point end = hc::now();
  dd diff = duration_cast<dd>(end - start);

  cout << "GeeksforGeeks Test Case\n---------------------------------\n";
  cout << "Expected Output: 23\nActual Output: Maximum Flow: " << maxFlow << '\n';
  cout << "Execution Time: " << diff.count() * MICRO << " microseconds\n\n\n";

  vli realworld = {{{1,15},{2,10}}, {{3,12},{4,5}}, {{4,8}}, {{5,10}}, {{5,10}}, {}};

  start = hc::now();
  maxFlow = DinicsAlgorithm(realworld);
  end = hc::now();
  diff = duration_cast<dd>(end - start);

  cout << "Real-World Scenario Word Problem\n---------------------------------\n";
  cout << "Expected Output: 20 Cars\nActual Output: Maximum Flow: " << maxFlow << " Cars\n";
  cout << "Execution Time: " << diff.count() * MICRO << " microseconds\n";

  return 0;
}

int DinicsAlgorithm(vli &adj) {
  vvi flow(adj.size());

  for(unsigned long int i = 0; i < adj.size(); i++) 
    for(unsigned long int j = 0; j < adj.at(i).size(); j++) flow.at(i).push_back(0);
  
  vli residual = adj;
  int blockingFlow = 0;

  while(1) {
    makeresidualidualGraph(residual, flow);
    vector<node> V(adj.size());
    // bfs returns false when sink T is impossible to reach in residual graph
    if(bfs(residual, V, 0) == false) return blockingFlow;
    
    // removes unecessary edges from residual graph
    for(unsigned long int i = 0; i < residual.size(); i++) {
      unordered_set<int> remove;

      for(list<pair<int,int>>::iterator it = residual.at(i).begin(); it != residual.at(i).end(); it++)
        if(V.at(i).dist + 1 != V.at(it->first).dist) remove.insert(it->first);
      
      list<pair<int,int>> newList;
      
      for(auto &x : residual.at(i))
        if(remove.find(x.first) == 0) newList.push_back({x.first, x.second});
      
      residual.at(i) = newList;
    }

    dfs(residual, V, blockingFlow);
    
    for(unsigned long int i = 0; i < residual.size(); i++) {
      int j = 0;
      list<pair<int,int>>::iterator it = adj.at(i).begin();
      for(auto &y : residual.at(i)) {
        while(it != adj.at(i).end() && (it++)->first != y.first) j++;
        flow.at(i).at(j++) += y.second;
      }
    } 

    residual = adj;
  }

  return blockingFlow;
}

bool bfs(vli &G, vector<node> &V, const unsigned long int s) {
  for(unsigned long int i = 0; i < V.size(); i++) {
    if(i == s) continue;
    V.at(i).color = 'W'; // White
    V.at(i).dist = INT_MAX;
    V.at(i).pred = -1;
  }
  V.at(s).color = 'G';
  V.at(s).dist = 0;
  V.at(s).pred = -1;
  queue<int> Q;
  Q.push(s);

  while(!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for(list<pair<int,int>>::iterator it = G.at(u).begin(); it != G.at(u).end(); it++) {
      if(V.at(it->first).color == 'W') {
        V.at(it->first).color = 'G';
        V.at(it->first).dist = V.at(u).dist + 1;
        V.at(it->first).pred = u;
        Q.push(it->first);
      }
    }

    V.at(u).color = 'B';
  }

  if(V.at(5).dist == INT_MAX) {
    return false;
  }
  return true;
}

void makeresidualidualGraph(vli &residual, vvi &flow) {

  for(unsigned long int i = 0; i < residual.size(); i++) {
    
    unsigned long int j = 0;
    unordered_set<int> remove;

    for(list<pair<int,int>>::iterator it = residual.at(i).begin(); it != residual.at(i).end(); it++) {
      
      if(j == flow.at(i).size()) break;
      if(flow.at(i).at(j) == -1) { // new edge, ignore
        j++;
        continue;
      }
      int residualCapacity = it->second - flow.at(i).at(j);
      if(residualCapacity == 0) {
        int newU = it->first; // new edge (u,v) = (newU, i)
        remove.insert(it->first);
        newEdge(residual, flow, newU, i, flow.at(i).at(j));
      } 
      else if(residualCapacity != it->second) {
        newEdge(residual, flow, it->first, i, it->second - residualCapacity); 
        it->second = residualCapacity;
      }
      j++;
    }

    list<pair<int,int>> newList;
    
    for(auto &x : residual.at(i)) {
      if(remove.find(x.first) == 0) {
        newList.push_back({x.first, x.second}); 
      }
    }
    
    residual.at(i) = newList;
  } 
}

void newEdge(vli &residual, vvi &flow, int &newU, const int &v, const int &f) {
  residual.at(newU).push_back({v, f});
  // if this is true, algorithm will run into this edge later and must ignore it
  (v < newU) ? flow.at(v).push_back(-1) : flow.at(v).push_back(0);
}

int dfs(vli &G, vector<node> &V, int &blockingFlow) {

    for(unsigned long int i = 0; i < G.size(); i++) {
        V.at(i).color = 'W';
        V.at(i).pred = -1;
        V.at(i).edge_t = 'U'; // unknown edge type
    }

    unsigned long int node = 0;
    int minVal = INT_MAX;
    vli flow = G;
    
    for(auto &x : flow)
      for(auto &y : x) y.second = 0;
    
    unordered_set<int> path;
    dfsVisit(G, flow, V, minVal, node, blockingFlow, path);
    G = flow;
    return 1;
}

int dfsVisit(vli &G, vli &flow, vector<node> &V, int &minVal, const unsigned long int &node, int &blockingFlow, unordered_set<int> &path) {
    V.at(node).color = 'G';
    for(list<pair<int,int>>::iterator it = G.at(node).begin(); it != G.at(node).end(); it++) {
        bool valid = true;

        for(list<pair<int,int>>::iterator it2 = flow.at(node).begin(); it2 != flow.at(node).end(); it2++) 
          if(it->first == it2->first && it->second == it2->second) valid = false;
        
        if(valid) {
            V.at(it->first).pred = node;
            V.at(it->first).edge_t = 'T'; // tree edge
            minVal = min(minVal, it->second);
            path.insert(node);
            dfsVisit(G, flow, V, minVal, it->first, blockingFlow, path);
            path.erase(node);
        }
    }

    if(node == G.size() - 1) {
      path.insert(node);
      vector<int> store;
      
      for(auto &x : path) 
        store.push_back(x);
      
      reverse(store.begin(), store.end());
      minVal = INT_MAX;

      for(unsigned long int i = 0; i < store.size() - 1; i++) {
        list<pair<int,int>>::iterator it2 = G.at(store.at(i)).begin();
        
        for(list<pair<int,int>>::iterator it = flow.at(store.at(i)).begin(); it != flow.at(store.at(i)).end(); it++) {
          if(it->first == store.at(i + 1)) minVal = min(minVal, it2->second - it->second);
          it2++;
        }
      }
      blockingFlow += minVal;
      for(unsigned long int i = 0; i < flow.size(); i++) 
        for(auto &y : flow.at(i)) 
          if(path.find(i) != 0 && path.find(y.first) != 0) y.second += minVal;  
      
      path.erase(node);
    }
    return 1;
}

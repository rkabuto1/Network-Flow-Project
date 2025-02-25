#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <utility>
#include <climits>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <tuple>

#define MICRO 1000000

using namespace std;
using namespace chrono;

class node {
    public:
        int pred; // predecessor
        int dist; // distance
        char color;
        char edge_t;
};

typedef vector<list<pair<int,int>>> vli;
typedef vector<list<tuple<int,int,int>>> vti; 
typedef vector<vector<int>> vvi;
typedef high_resolution_clock hc;
typedef duration<double> dd;

int DinicsAlgorithm(vli &adj);
void makeresidualidualGraph(vli &residual, vvi &flow);
void newEdge(vli &residual, vvi &flow, int &newU, const int &v, const int &f);
bool bfs(vli &G, vector<node> &V, const unsigned long int s);
int dfs(vli &G, vector<node> &V, int &blockingFlow);
int dfsVisit(vli &G, vli &flow, vector<node> &V, int &minVal, const unsigned long int &node, int &blockingFlow, unordered_set<int> &path);

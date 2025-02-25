#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

bool search(vector<vector<int>>& graph, int src, int dest, vector<int>& prev) {
    int n = graph.size();
    vector<bool> seen(n, false);
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty()) {
        auto [cur, par] = q.front();
        q.pop();

        if (seen[cur]) continue;
        seen[cur] = true;
        prev[cur] = par;

        if (cur == dest) return true;

        for (int next = 0; next < n; next++) {
            if (!seen[next] && graph[cur][next] > 0) {
                q.push({next, cur});
            }
        }
    }
    return false;
}

int flow(vector<vector<int>>& cap, int src, int dest) {
    int n = cap.size();
    vector<vector<int>> graph = cap;
    vector<int> prev(n);
    int total = 0;

    while (search(graph, src, dest, prev)) {
        int flowAmt = INT_MAX;
        for (int v = dest; v != src; v = prev[v]) {
            int u = prev[v];
            flowAmt = min(flowAmt, graph[u][v]);
        }

        for (int v = dest; v != src; v = prev[v]) {
            int u = prev[v];
            graph[u][v] -= flowAmt;
            graph[v][u] += flowAmt;
        }

        total += flowAmt;
    }

    return total;
}

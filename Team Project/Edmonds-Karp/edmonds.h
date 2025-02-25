#ifndef EDMONDS_H
#define EDMONDS_H

#include <vector>
bool search(std::vector<std::vector<int>>& graph, int src, int dest, std::vector<int>& prev);
int flow(std::vector<std::vector<int>>& cap, int src, int dest);

#endif


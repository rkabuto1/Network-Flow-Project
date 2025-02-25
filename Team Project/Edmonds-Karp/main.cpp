#include <iostream>
#include <vector>
#include <chrono>
#include "edmonds.h"
using namespace std;

int main() {  
    cout << "GeeksforGeeks Test Case\n";
    cout << "---------------------------------\n";
    vector<vector<int>> gfgGraph = {
        {0, 16, 13, 0, 0, 0}, 
        {0, 0, 10, 12, 0, 0}, 
        {0, 4, 0, 0, 14, 0}, 
        {0, 0, 9, 0, 0, 20}, 
        {0, 0, 0, 7, 0, 4}, 
        {0, 0, 0, 0, 0, 0}
    };
    int source = 0; 
    int sink = 5;  

    auto start = std::chrono::high_resolution_clock::now();
    int maxFlow = flow(gfgGraph, source, sink);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    cout << "Expected Output: 23\n";
    cout << "Actual Output: Maximum Flow: " << maxFlow << endl;
    cout << "Execution Time: " << duration.count() << " microseconds\n\n";
    cout << "Real-World Scenario Word Problem\n";
    cout << "---------------------------------\n";
    vector<vector<int>> trafficGraph = {
        {0, 15, 10, 0,  0,  0}, 
        {0,  0,  0, 12,  5,  0}, 
        {0,  0,  0,  0,  8,  0}, 
        {0,  0,  0,  0,  0, 10}, 
        {0,  0,  0,  0,  0, 10}, 
        {0,  0,  0,  0,  0,  0}  
    };
    source = 0; 
    sink = 5;      
    start = std::chrono::high_resolution_clock::now();
    maxFlow = flow(trafficGraph, source, sink);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);    
    cout << "Expected Output: 20 Cars\n";
    cout << "Actual Output: Maximum Flow: " << maxFlow << " Cars\n";
    cout << "Execution Time: " << duration.count() << " microseconds\n";

    return 0;
}


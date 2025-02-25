-=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=
This part of the project demonstrates the implementation of the Edmonds-Karp Algorithm to solve the Maximum Flow Problem. The program models a real-world scenario to compute the maximum possible flow through a network of nodes and edges with capacity constraints. The first test case is a reference problem from GeeksforGeeks with a known solution, allowing for verification against an expected result of 23. The second test case models a real-world traffic network scenario, determining the maximum number of cars that can flow from a starting intersection to a destination without exceeding road capacities, with an expected output of 20 cars.

The input for the program is represented through an adjacency matrix, where rows and columns correspond to nodes, and values represent the capacity of edges between nodes. A value of 0 indicates no direct connection.
-=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=
The Edmonds-Karp Algorithm is a specialized version of the Ford-Fulkerson method. Starting with an initial flow of 0, the algorithm iteratively finds augmenting paths using Breadth First Search, computes the bottleneck capacity along these paths, updates the residual graph, and increases the total flow. The process repeats until no more augmenting paths are available and shows maximum flow.

The time complexity of the Edmonds-Karp Algorithm is O(V * E^2), where V is the number of vertices (nodes) and E is the number of edges. 
BFS runs in O(E), and the algorithm can execute BFS at most O(E*V) times, making it computationally efficient for medium sized graphs.
-=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=
To run the Program
	1) Make - To compile all files necessary in the program
	2) ./edmonds - To run the executable
	3) Make clean - To remove executables
-=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=


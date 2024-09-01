
// number-of-connected-components-in-an-undirected-graph/description 
// 📌 Number of connected components 

// Inorder to traversal the all sub-grpahs,we need visited array to keep track the,
// this current node is visited or not visited
// as we know (Traversal Algorithm) degisn, in this such manner, they covered all the nodes!

// step-1 create the visited array
// step-2 traversal the all nodes
// step-3 if you visit the current node, Then mark visited this current nodes

#include <bits/stdc++.h>
using namespace std;

// creation of visited array using Vector - STL
// we can also try this int vis[n] = {0};
vector<int> vis(N,0);

int numberConnected = 0;
// the graph starting from the 0th vertex
for(int currentNode = 0; currentNode < N; currentNode ++ ){

    // currentNode is not alredy visited then call DFS/BFS algorithm
    // we will use in future problems
    if(vis[currentNode] == 0){
        // BFS() algorithm called
        // DFS() algorithm called 
        numberConnected ++;
    }
}

cout << numberConnected << endl;

//📌 BFS of graphs
// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
    // Inorder to perfrom BFS Algorithm, we need queue dsa, array visited, array for storing the resullt-Data 
        vector<int> resultArray;
        vector<int> visitedArray(V,0);
        queue<int> queueDSA;
        
    // The task is to do Breadth First Traversal of this graph starting from 0.
    // First node is to be mark visited for not-coming again same node
    
       // push into queue, mark visited starting node of graphs using 1
        queueDSA.push(0);
        visitedArray[0] = 1;
    
    // Perform BFS algorithm 
        while(!queueDSA.empty()){
           int node = queueDSA.front();
           queueDSA.pop();
    
    // BFS traversal of the graph starting from the 0th vertex from left to right.
    // Store into the result-array everyNodes
    
           resultArray.push_back(node);
           //  adjacency list as input parameters
           // When you popped the nodes,Then go to adj-list,checkout the currentNode is visited or not 
           // if current node (adjlist node) is visited alredy no need push into queue
           // if current node is not visited , we have to push into queue and mark visited for future calls
           for(auto connectedNodes : adj[node]){
               if(visitedArray[connectedNodes] == 0){
                   queueDSA.push(connectedNodes);
                     visitedArray[connectedNodes] = 1;
               }
           }
        }
        
        // return the result array 
        return resultArray;
    }
};

// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)
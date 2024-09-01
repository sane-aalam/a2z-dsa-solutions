
// 📌 Thoery Read your notes
// 1. Matrix way
// 2. adjacency list way

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        
        vector<vector<int>> adj(V);
        
        // we have to iterate the edeges
        for(auto it : edges){
            int firstNode = it.first;
            int secondNode = it.second;
            
            adj[firstNode].push_back(secondNode);
            adj[secondNode].push_back(firstNode);
        }
        return adj;
    }
};

// 📌 Time and Space Complexity
// Time Complexity: The time complexity of this code is O(E), where E is the number of edges. This is because we iterate through each edge in the edge_list once, and for each edge, we perform constant-time operations (appending to adjacency lists).

// 📌 Space Complexity: The space complexity is O(V + E), where V is the number of vertices and E is the number of edges. We store the adjacency information for each vertex in the adjacency_list, which requires space for V vertices and E edges.
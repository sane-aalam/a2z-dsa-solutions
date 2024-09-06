class Solution {
  private:
   bool cycle(int node, int parent,vector<int> vis,vector<int> adj[]){
       
       vis[node] = 1;
       
       for(auto currentNode : adj[node]){
           if(vis[currentNode] == 0){
               if(cycle(currentNode,node,vis,adj) == true){
                   return true;
               }
           }else if(currentNode != parent){
               return true;
           }
       }
       return false;
   }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        
        for(int node = 0; node < V; node++){
            if(vis[node] == 0){
                if(cycle(node,-1,vis,adj) == true){
                    return true;
                }
            }
        }
        return false;
    }
};
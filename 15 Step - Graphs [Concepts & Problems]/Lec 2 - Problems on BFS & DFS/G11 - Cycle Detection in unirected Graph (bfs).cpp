class Solution {
  private:
   bool BFS(int node, vector<int>& visted,vector<int> adj[]){
       
       // apply Breath first search algorithm
       queue<pair<int,int>> Queue;
       // don't have any parent node so we can push random parent value
       Queue.push({node,-213});
       visted[node] = 1;
       
       while(!Queue.empty()){
           int node = Queue.front().first;
           int parent = Queue.front().second;
           
           Queue.pop();
           
           for(auto conncetNode : adj[node]){
               if(visted[conncetNode] == 0){
                   visted[conncetNode] = 1;
                   Queue.push({conncetNode,node});
               // dont't have parent node
               // i can say - someone is already touched 
               }else if(parent != conncetNode ){
                   return true;
               }
           }
       }
       // if you have traversed the complete graphs, not found the cycle
       // then cycle nahi hai na bhai
       return false;
   }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visted(V,0);
        
        // connceted componets maintan karna hai
        // graph has 0-base indexes 
        for(int node = 0; node < V; node++ ){
            if(visted[node] == 0){
                if(BFS(node,visted,adj) == true){
                    return true;
                }
            }
        }
        
        return false;
    }
};
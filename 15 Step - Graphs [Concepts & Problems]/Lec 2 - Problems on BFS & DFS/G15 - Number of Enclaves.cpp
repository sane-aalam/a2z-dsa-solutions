class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        // re-use the code
        vector<vector<int>> board = grid; 
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        
        // 1. Traversal the boundary of the matrix collect all O's 
        for(int i = 0; i < n; i++){
            for(int j = 0;j<m; j++){
                if(i == 0 or i == n-1 or j == 0 or j == m-1){
                    if(board[i][j] == 1){
                        // we have to push into the queue and also marked visted
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        
        // 2. Apply BFS algorithm go the it's connected nodes
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
                
            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,-1,0,1};

            for(int directionMover = 0; directionMover<4; directionMover++){
                int newrow = delrow[directionMover] + row;
                int newcol = delcol[directionMover] + col;

                //****** need to follow three condtions ***** 
                // valid reange + not alredy visted this cell
                // connectecd o"s avaiable
                
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m 
                  && vis[newrow][newcol] == 0 && board[newrow][newcol] == 1){
                    q.push({newrow,newcol});
                    vis[newrow][newcol] = 1;
                }
         
            }
        }
        
        // 3. convert o"s into the X's which are not connceted to the boundary of the matrix
        
        int NumberEncaves = 0;
        for(int row = 0; row <n; row++){
            for(int col = 0; col<m; col++){
                if(board[row][col] == 1 and vis[row][col] == 0){
                    NumberEncaves ++;
                }
            }
        }
        return NumberEncaves;
    }
};
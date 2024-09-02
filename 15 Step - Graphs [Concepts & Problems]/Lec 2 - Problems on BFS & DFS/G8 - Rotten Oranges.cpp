
// ✅ step-1 collect all already oranges into the queue
// ✅ step-2 Apply BFS Algorithm, Why BFS algorithm, [fast as compare to DFS]
// ✅ step-3 keep track the time (minimum time taken to rottern all oranges)
        // you should remember this conditon
        // 0 representing an empty cell,
        // 1 representing a fresh orange, or
        // 2 representing a rotten orange.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

          int n = grid.size();
          int m = grid[0].size();

          queue<pair<int,pair<int,int>>> q;
          vector<vector<int>> vis(n,vector<int> (m,0));

          for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 2){
                    // push into queue and mark visited that cell
                    q.push({0,{row,col}});
                    vis[row][col] = 1;
                }
            }
          }

          int TimeTakeRottens = 0;
          // BFS Algorithm + 4 direction matrix traversal
          while(!q.empty()){
             int time = q.front().first;
             int row = q.front().second.first;
             int col = q.front().second.second;
             q.pop();

             TimeTakeRottens = max(TimeTakeRottens,time); 

    //  Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
              int delrow[4] = {-1,0,1,0};
              int delcol[4] = {0,1,0,-1};

                for(int direction = 0; direction < 4; direction++){
                    int newrow = delrow[direction] + row;
                    int newcol = delcol[direction] + col;

                    // ✅ there are condtion, should make sure
                    // ✅ condtion-1 row,col indexes not gonna to out of the boundary 
                    // ✅ condition-2 current cell is representing a fresh orange 1
                    // ✅ condition-3 not alredy visited this current cell
                    if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m 
                     && grid[newrow][newcol] == 1 && vis[newrow][newcol] == 0 ){
                         q.push({time+1,{newrow,newcol}});
                         grid[newrow][newcol] = 2;
                         vis[newrow][newcol] = 1;
                     }
                }
          }
            
              // ✅ Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
            for(int row = 0; row < n; row++){
                    for(int col = 0; col < m; col++){
                        if(grid[row][col] == 1 && vis[row][col] == 0){
                            return -1;
                        }
                    }
            }

            return TimeTakeRottens;
    }
};
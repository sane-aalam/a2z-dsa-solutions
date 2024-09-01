
// 📌 200. Number of Islands
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// ✅ DFS solution
class Solution {
private:
    void dfs(int row, int col, vector<vector<char>> & grid, vector<vector<int>> & visited){
         
        int n = grid.size();
         int m = grid[0].size();
          
          visited[row][col] = 1;
          int delrow[4] = {-1,0,1,0};
          int delcol[4] = {0,1,0,-1};

          for(int direction = 0; direction < 4; direction++){
            int newrow = delrow[direction] + row;
            int newcol = delcol[direction] + col;

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == '1'
               && visited[newrow][newcol] == 0){
                   dfs(newrow,newcol,grid,visited);
               }
          }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
         int n = grid.size();
         int m = grid[0].size();

         vector<vector<int>> visited(n,vector<int>(m,0));

         int NumberIslands = 0;

         for(int row = 0; row < n; row ++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == '1' && visited[row][col] == 0){
                    dfs(row,col,grid,visited);
                    NumberIslands ++;
                }
            }
         }

         return NumberIslands;
    }
};

// ✅ BFS solution
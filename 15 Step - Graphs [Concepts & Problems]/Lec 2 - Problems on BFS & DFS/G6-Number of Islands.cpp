
// 📌 200. Number of Islands
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 

// Some condtions you must checkout the 
// condtion-1 valid range ( not gonna to out the bound of the matrix)
// conditon-2 not already visited
// condition-3 is lands(island)


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

// ❌ ERROR: AddressSanitizer: heap-buffer-overflow on address
// we have to understand, read about this error
// In simple words it is segmentation fault with the variable created using new keyword as all that goes into heap area of memory.
// ✅ syntax error - missing (&& into code)

class Solution {
private:
    void BFSTraversalAlgorithm(int row, int col, vector<vector<char>>& grid,vector<vector<int>> & visited ){

        // we are using BFS algorithm to travesal all four edges of the grid are all surrounded by water.
        // need to create queue<row,col> 

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col] = 1;

        while(!q.empty()){
             int row = q.front().first;
             int col = q.front().second;
             q.pop();

           int delrow[4] = {-1,0,1,0};
           int delcol[4] = {0,1,0,-1};
            
            //  all four edges of the grid are all surrounded by water.
            //  traverse all four direction of matrix [up-right-down-left]
             for(int direction = 0; direction < 4; direction++){

                // better way to find new row, new column (indexes value)
                int newrow = delrow[direction] + row;
                int newcol = delcol[direction] + col;

                // Some condtions you must checkout the 
                // condtion-1 valid range ( not gonna to out the bound of the matrix)
                // conditon-2 not already visited
                // condition-3 is lands(island)

                // missing && here (error fix it)
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == '1' &&
                          visited[newrow][newcol] == 0){
                        q.push({newrow,newcol});
                        visited[newrow][newcol] = 1;
                }
             }
        }
          
    }
public:
    int numIslands(vector<vector<char>>& grid) {
         int n = grid.size();
         int m = grid[0].size();

         vector<vector<int>> visited(n,vector<int> (m,0));
         int NumberIslands = 0;

         for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == '1' && visited[row][col] == 0){
                     BFSTraversalAlgorithm(row,col,grid,visited);
                     NumberIslands ++;
                }
            }
         }
         return NumberIslands;
    }
};


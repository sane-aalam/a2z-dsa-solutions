
// base case 
// When you reached the target(ending cell) within number of empty cell total, return 1;
// When you are gonna to out of bounary of matrix 

// backtracking 
// do your work + explore + undo your work(for future calls)

class Solution {
public:
    int solve(int i,int j,int count,int& nonObstacleTotal,vector<vector<int>>& grid){
        //base case1
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1) 
              return 0;      
                
        //base case2
        if(grid[i][j]==2){
            if(count==nonObstacleTotal)
                return 1;
            return 0;
        }
        
        //------------- Try all possible ways ----------
        // Do your work + explore the worlds + undo your works
        grid[i][j]=-1;
        //running down all 4 possibilities 
        int up=solve(i-1,j,count+1,nonObstacleTotal,grid);
        int down=solve(i+1,j,count+1,nonObstacleTotal,grid);
        int right=solve(i,j+1,count+1,nonObstacleTotal,grid);
        int left=solve(i,j-1,count+1,nonObstacleTotal,grid);

        //backtracking 
        grid[i][j]=0;
        int allpossiblePaths = (up+down+right+left);          
        return allpossiblePaths;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        // startrow, start column value
         //empty is cells with 0
        //x and y are coordinates of starting point marked with 1 in grid
        // can be happend start[row,col] can be (not (0,0) cell) we have to find the cell indexes value
        int nonObstacleTotal = 1;
        int count = 0;
        int startRow = 0;
        int startCol = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 0){
                    nonObstacleTotal++;
                }else if(grid[row][col] == 1){
                    startRow = row;
                    startCol = col;
                }
            }
        }
        return solve(startRow,startCol,count,nonObstacleTotal,grid);
    }
};
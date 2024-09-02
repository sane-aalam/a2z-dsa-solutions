
// 📌 breakdown of problem statement!
// ✅ 1. You are also given three integers sr, sc, and color
// ✅ 2. You should perform a flood fill on the image starting from the pixel image[sr][sc]. 
            // ( startcolor = image[row][col] )
// ✅ 3. To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
// ✅ 4. Try to think every cell as node, convert into NewColor 
// ✅ 5. DFS,BFS Algorithm can try!

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         
         // for understanding,we have to store using better variable naming 
         int startColor = image[sr][sc];
         int newColor = color;
         int n = image.size();
         int m = image[0].size();

        // pair used int STL (morning you have paracticed)
         queue<pair<int,int>> q;
         vector<vector<int>> vis(n,vector<int>(m,0));

         // Extra space used
         // not want to change original given matrix 
         vector<vector<int>>& copyMatrix = image;

         q.push({sr,sc});
         vis[sr][sc] = 1;
         copyMatrix[sr][sc] = newColor;

         while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // Why i have created copy matrix,reason, don't want to change original data
             int delrow[4] = {-1,0,1,0};
             int delcol[4] = {0,1,0,-1};

                for(int direction = 0; direction < 4; direction++){
                    int newrow = delrow[direction] + row;
                    int newcol = delcol[direction] + col;

                    if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && vis[newrow][newcol] == 0 
                     && image[newrow][newcol] == startColor){
                         q.push({newrow,newcol});
                         vis[newrow][newcol] = 1;
                         copyMatrix[newrow][newcol] = newColor;
                     }
                }
         }
         
         return copyMatrix;
    }
};

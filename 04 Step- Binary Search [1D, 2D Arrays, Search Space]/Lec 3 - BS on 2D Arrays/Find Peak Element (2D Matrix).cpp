// 1901. Find a Peak Element II

// Tc - 0(N2)
// sc - 0(1)
// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
// solution should be good like peak-Element problem-1 

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxElement = INT_MIN;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int currElement = mat[i][j];
                if(currElement > maxElement){
                    maxElement = currElement;
                }
            }
        }

         int row = -1;
         int col = -1;
         for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == maxElement){
                    row = i;
                    col = j;
                    break;
                }
            }
        }
        return {row,col};
    }
};

// solution using Binary Search
// think like Peak Element Problem-1 
// arr[mid-1] < arr[mid] > arr[mid+1]


class Solution {
private:
     // traveral the entire column
     // Tc 0(n)
    int findMaxRowIndex(vector<vector<int>>& mat,int n, int col){
        int maxElement = -1;
        int index = -1;
        for(int i = 0; i<n; i++){
            if(mat[i][col] > maxElement){
                maxElement = mat[i][col];
                index = i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
        int n = mat.size();
        int m = mat[0].size();

        int start = 0;
        int end = m - 1;
        while(start <= end){
            int mid = (start+ end)/2;
            int maxRowIndex = findMaxRowIndex(mat,n,mid);

            // find left + right [arr[mid-1] or arr[mid+1]] value 
            // to check out the this condition arr[mid-1] < arr[mid] > arr[mid+1]
            // prev < curr && curr < next (modification of matrix way)
            int curr = mat[maxRowIndex][mid];
            int prev = mid -1 >= 0 ? mat[maxRowIndex][mid-1] : -1;
            int next = mid +1 < m ? mat[maxRowIndex][mid+1] : -1;

            // conditon should follow to peak element 
            if(prev < curr && curr > next){
                return {maxRowIndex,mid};
            }else if(prev > curr){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return {-1,-1};
    }
};
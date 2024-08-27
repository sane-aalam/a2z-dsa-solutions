class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        set<int> st;
        
        // traverse the first array
        // push element into set 
        for(int index = 0; index < n; index++){
            st.insert(arr1[index]);
        }
        
        // travese the second array 
        // push element into set 
        for(int index = 0; index < m; index++){
            st.insert(arr2[index]);
        }
        
        vector<int> result;
        for(auto it : st){
            result.push_back(it);
        }
        
        return result;
    }
};
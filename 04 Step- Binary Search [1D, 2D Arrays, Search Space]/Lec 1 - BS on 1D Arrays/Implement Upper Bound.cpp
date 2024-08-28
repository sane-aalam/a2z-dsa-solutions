


int FindGreater(int arr[], int n, int x){
    int start = 0;
        int end = n - 1;
        int key = x;
        
        int mid = start + (end-start)/2;
        
        int result = -1;
        
        while(start <= end){
            if(arr[mid] == key){
                return arr[mid];
            }else if(arr[mid] <= key){
                start = mid + 1;
            }else{
        // element which is greater than or equal to X.
                result = arr[mid];
                end = mid - 1;
            }
            mid = start + (end-start)/2;
        }
        return result;
}

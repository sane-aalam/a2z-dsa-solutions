int FindSmaller(int arr[], int n, int x){
     int start = 0;
        int end = n - 1;
        int key = x;
        
        int mid = start + (end-start)/2;
        
        int result = -1;
        
        while(start <= end){
            if(arr[mid] == key){
                return arr[mid];
            }else if(arr[mid] <= key){
    // element which is smaller than or equal to X.
                result = arr[mid];
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end-start)/2;
        }
        return result;
}




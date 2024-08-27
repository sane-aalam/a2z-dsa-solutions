
#include <bits/stdc++.h>
using namespace std;

// 1.Linear search algorithm (normal Traversal the array)
class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searched
    int searchInSorted(int arr[], int N, int K) {
        
        for(int i = 0; i<N; i++){
            if(arr[i] == K){
                return 1;
            }
        }
        return -1;
    }
};

//2. using While-loop
class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searched
    int searchInSorted(int arr[], int N, int K) {
        
        // Your code here
        int currentIndex = 0;
        int sizeOfArray = N;
        int targetValue = K;
        
        while(currentIndex < sizeOfArray){
            if(arr[currentIndex] == targetValue){
                return 1;
            }
            currentIndex++;
        }
        return -1;
    }
};
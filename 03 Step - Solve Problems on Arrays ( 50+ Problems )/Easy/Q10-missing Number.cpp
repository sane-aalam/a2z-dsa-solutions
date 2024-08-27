
//* One of best problem today,i have solved!
//* Thank you!
//* Try to solve all possible way
// bruth force 
// better approach
// optimization of math way
// optimization of xor way (opreator used here)

// BruthForce Appraoch - 
// Ask give array, this is present into the array
// ? does 1 exit?
// ? does 2 exit?
// ? does 3 exit? 
// TC - 0(n2)
// SC - 0(1)

int missingNumber(vector<int>&a, int N) {
    // Write your code here.

    for(int i = 1; i<=N; i++){
        int flag = 0;
        int missingElement = i;
        for(int j = 0; j<N-1; j++){
             if(a[j] == missingElement){
                 flag = 1;
                 break;
             }
        }

        // check if the element is missing
        //i.e flag == 0:
        if(flag == 0){
            return i;
        }
    }
    return -1;
}


//Better approach - HashMap(visited or not visited concept)
// TC - 0(n)
// SC - 0(n)

int missingNumber(vector<int>&a, int N) {
    // Write your code here.

// You need to apply (Algorithm)
// currentElement is visited or not visited
// currentElement is present, mark currentElement is visited
// traversal hashMap array, anyone have missing, Then return missingElement


    int hashMap[N+1] = {0};
    int missingElement = -1;

    // one element is not present into the array
    // size = N-1
    for(int i = 0; i<N-1; i++){
        hashMap[a[i]] = 1;
    }

    for(int i = 1; i<=N; i++){
        if(hashMap[i] == 0){
           missingElement = i;
           break;
        }
    }
    return missingElement;
}

// optimization of math way
// TC - 0(n)
// Sc - 0(1)
int missingNumber(vector<int>&a, int N) {
    // Write your code here.
    int sum = 0;
    int NthSum = (N*(N+1)/2);
    for(int i = 0; i < a.size(); i++){
        sum = sum + a[i];
    }

    return NthSum - sum;
}

//sol.2.best Optimal approach
// optimization of xor way
// TC - 0(n)
// Sc - 0(1)

int missingNumber(vector<int>&a, int N) {

    int xor1=0;
    int xor2 =0;
    int n = N-1;
    for(int i=0; i<n; i++){
        xor2= xor2 ^ a[i];
        xor1= xor1 ^ (i+1);

    }

    xor1 = xor1^N;
    return xor1^xor2;
}
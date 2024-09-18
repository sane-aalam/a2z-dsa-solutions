/*
Algorithm - Jo kaha wo kar do questions-
1. last index point nikal lo (M,P,G) (last metal, last palatsic, last garbage)
2. prefix sum (find of time) array
3. result =+ prfix[M-1], same for P,G
*/

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
         int n = garbage.size();

     //gi pi mi all store lastindex of glass plastic metal respectively
         int lastG = -1;
         int lastP = -1;
         int lastM = -1;
        
     //  Picking up one unit of any type of garbage takes 1 minute.
     // count all garbage by 1
     // time array se traveral value we will find it 
         int ans = 0;
         for(int i = 0; i<n; i++){
            // go each char one by one
            // checkout the last index value 
            for(auto & ch : garbage[i]){
                if(ch == 'G'){
                    lastG = i;
                    ans++;
                }else if(ch == 'M'){
                    lastP = i;
                    ans++;
                }else{
                    lastM = i;
                    ans++;
                }
            }
         }

         for(int i = 1; i<travel.size(); i++){
            travel[i] += travel[i-1];
         }

// There are three garbage trucks in the city, each responsible for picking up one type of garbage. 
// Each garbage truck starts at house 0 and must visit each house in order; 
// however, they do not need to visit every house.
         ans += lastG > 0? travel[lastG-1]:0;
         ans += lastP > 0? travel[lastP-1]:0;
         ans += lastM > 0? travel[lastM-1]:0;     
         return ans;    
    }
};

// Fib series 
// Tc - 0(n)
// Sc - 0(1)


class Solution {
public:
    int fib(int n) {
            int prev1 = 0;
            int prev2 = 1;

            for(int i = 2; i<=n; i++){
                int curr_i = (prev_i + prev2_i);
                prev2 = prev1;
                prev1 = curr_i;
            }
            return prev1;
    }
};


// 
class Solution {
public:
    int fib(int n) {
            int prev1 = 0;
            int prev2 = 1;

            for(int i = 2; i<=n; i++){
                int curr_i = (prev_i + prev2_i);
                prev2 = prev1;
                prev1 = curr_i;
            }
            return prev1;
    }
};
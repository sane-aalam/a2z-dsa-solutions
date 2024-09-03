
// Fib series (pattern)
// Tc - 0(n)
// Sc - 0(1)

class Solution {
public:
    int climbStairs(int n) {
         int prev_i = 1;
            int prev2_i = 1;

            for(int i = 2; i<=n; i++){
                int curr_i = (prev_i + prev2_i);
                prev2_i = prev_i;
                prev_i = curr_i;
            }
            return prev_i;
    }
};
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
         
         int fiveRupess = 0;
         int tenRupess = 0;
         int n = bills.size();

// Each customer will only buy one lemonade and pay with either a $5, $10, or $20 
// bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise
// simple implementation of if-else statement of code 
// time complexity of problem - 0(N)
// space compleixty of problem - 0(n)
         for(int index = 0; index < n; index ++){
            if(bills[index] == 5){
                fiveRupess++;
            }else if(bills[index] == 10){
            // aapne pass bapas dene ko na ho then return false
                if(fiveRupess == 0){
                    return false;
                }else{
            // customers give you one 10's rupess note
            // you will be him, back 5's rupess note
                    fiveRupess--;
                    tenRupess++;
                }
            }else if(bills[index] == 20){
            // pahle try karo minimum 5 rupess or 10 rupess dene kar 
                if(fiveRupess > 0 and tenRupess > 0){
                    fiveRupess--;
                    tenRupess--;
                }else if(fiveRupess >= 3){
                    fiveRupess = fiveRupess - 3;
                }else{
                    return false;
                }
            }
         }
        return true;
    }
};
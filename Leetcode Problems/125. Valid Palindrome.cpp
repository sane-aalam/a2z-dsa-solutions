// tolower() function to convert uppercase to lowercase char 
// easy to understand solution
// step-1 convert uppercase to lowercase
// step-2 reverse the currentstring
// step-3 compare with orinignal string value

class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        int n = s.length();
        for(int i = 0; i<n; i++){
            int value = (int)s[i];
            char ch = s[i];
            // s consists only of printable ASCII characters.
            // lowercase ASCII value
            // uppwercase ASCII value
            // number ASCII value 
            if((value > 64 && value < 91)
                      or (value > 96 && value < 123)
                          or (value > 47 && value < 58) ){ 
                            res += tolower(ch);
            }
        }

        string check = res;
        // STL
        reverse(check.begin(),check.end());
        // cout << res << endl;
        // cout << check << endl;
        // both are equal or not 
        return res == check;
    }
};
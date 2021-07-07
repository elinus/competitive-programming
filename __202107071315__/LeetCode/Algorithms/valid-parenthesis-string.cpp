class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for(char c : s) {
            if (c == '(') {
                low += 1;
                high += 1;
            } else if (c == ')') {
                low -= 1;
                high -= 1;
            } else if (c == '*') {
                low -= 1;
                high += 1;
            }
            low = max(low, 0);
            if (high < 0) return false;
        }
        return low == 0; 
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (!n) return {};
        
        reverse(digits.begin(), digits.end());
        while (digits.back() == 0 && digits.size() > 1) digits.pop_back();
        int carry = 0;
        
        if ((digits[0] + 1) > 9) {
            digits[0] = 0;
            carry = 1;
        } else {
            digits[0] += 1;
        }
        for(int i = 1; i < n; ++i) {
            if((digits[i] + carry) > 9) {
                digits[i] = 0;
                carry = 1;
            } else {
                digits[i] += carry;
                carry = 0;
            }
        }
        if (carry) {
            digits.push_back(carry);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

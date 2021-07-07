class Solution {
public:
    int reverse(int x) {
        if (x <= INT_MIN || x >= INT_MAX) return 0;
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = sign * x;
        }
        int num = 0;
        while (x) {
            long expr = static_cast<long>(num) * 10 + x % 10;
            if (expr < INT_MIN || expr > INT_MAX) return 0;
            num = (num * 10) + (x % 10);
            x /= 10;
        }
        return sign * num; 
    }
};

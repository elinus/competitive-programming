class Solution {
    const int bits = 8;
public:
    bool isPowerOfFour(int num) {
        for (auto i = 0; i < (bits * sizeof(int)); ++i) {
            if (pow(4, i) == num) return true; 
        }
        return false;
    }
};

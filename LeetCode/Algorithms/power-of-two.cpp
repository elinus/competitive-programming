#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int bits = 8;
public:
    bool isPowerOfTwo(int n) {
        for (auto i = 0; i < (bits * sizeof(int)); ++i) {
            if (pow(2, i) == n) return true; 
        }
        return false;          
    }
};

int main (int argc, char *argv[]) {
    cout << sizeof(int) << endl;
    Solution sol;
    cout << sol.isPowerOfTwo(1) << endl;
    cout << sol.isPowerOfTwo(16) << endl;
    cout << sol.isPowerOfTwo(218) << endl;
    return 0;
}


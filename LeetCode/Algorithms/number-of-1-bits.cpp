#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (uint32_t i = 0; i < 32; ++i) {
            if (n & (1 << i)) count++;
        }
        return count;
    }
};

int main (int argc, char *argv[]) {
    uint32_t uint = 3;
    cout << uint << endl;
    return 0;
}


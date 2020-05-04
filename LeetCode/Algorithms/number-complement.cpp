#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        vector<int> bits;
        while (num) {
            bits.push_back(!(num % 2));
            num /= 2;
        }
        num = 0;
        int p = 0;
        for (auto it = bits.begin(); it != bits.end(); ++it) {
            num += ((*it) * pow(2, p++)); 
        }
        return num;
    }
};

int main (int argc, char *argv[]) {
    Solution sol;
    cout << sol.findComplement(5) << endl;
    cout << sol.findComplement(1) << endl;
    cout << sol.findComplement(0) << endl;
    cout << sol.findComplement(15) << endl;
    cout << sol.findComplement(10) << endl;
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<bool> jewels(128, false);
        for (auto i = 0; i < J.size(); ++i) {
            jewels[J[i] - '0'] = true;
        }
        int count_js = 0;
        for (auto i = 0; i < S.size(); ++i) {
            if (jewels[S[i] - '0']) count_js++;
        }
        return count_js;
    }
};

int main (int argc, char *argv[]) {
    Solution sol;
    
    string J = "aA", S = "aAAbbbb";
    cout << sol.numJewelsInStones(J, S) << "\n";
    
    J = "z", S = "ZZ";
    cout << sol.numJewelsInStones(J, S) << "\n";

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool backspaceCompare(string S, string T) {
            if(S == "" && T == "") return true;
            int j = 0;
            for(int i = 0; i < S.size(); ++i) {
                if (S[i] == '#') {
                    if (j > 0) j--;
                    continue;
                }
                S[j++] = S[i];
            }
            S.resize(j);

            j = 0;
            for(int i = 0; i < T.size(); ++i) {
                if (T[i] == '#') {
                    if (j > 0) j--;
                    continue;
                }
                T[j++] = T[i];
            }
            T.resize(j);
            if (S == T) return true;
            return false;
        }
};

int main (int argc, char *argv[]) {
    return 0;
}


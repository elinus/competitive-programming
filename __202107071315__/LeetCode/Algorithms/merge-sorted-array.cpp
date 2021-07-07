#include <bits/stdc++.h>

using namespace std;

void print(const vector<int> & v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

class Solution {
    public:
        void merge(vector<int>& A, int m, vector<int>& B, int n) {
            int i = m - 1;
            int j = n - 1;
            int k = m + n - 1;

            while (k >= 0) {
                if (j < 0 || (i >= 0 && A[i] > B[j]))
                    A[k--] = A[i--];
                else
                    A[k--] = B[j--];
            }
        }
};

int main (int argc, char *argv[]) {
    vector<int> v1 = {4, 5, 6, 0, 0, 0}, v2 = {1, 2, 3};
    Solution sol;
    sol.merge(v1, 3, v2, 3);
    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " ";
    }
    cout << "\n";

    return 0;
}


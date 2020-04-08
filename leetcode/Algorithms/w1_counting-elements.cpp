#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countElements(vector<int>& arr) {
            map<int, int> lookup;
            for (auto i = 0; i < arr.size(); ++i) {
                if (lookup.find(arr[i]) == lookup.end()) {
                    lookup[arr[i]] = 1;
                } else {
                    lookup[arr[i]] += 1;
                }
            }
            for(auto i = lookup.begin(); i != lookup.end(); ++i) {
                cout << i->first << " " << i->second << "\n";
            }
            sort(arr.begin(), arr.end());
            int res = 0;
            for (auto i = 0; i < arr.size(); ++i) {
                if (lookup.find(arr[i] + 1) != lookup.end()) {
                    res += lookup[arr[i]];
                    //res += min(lookup[arr[i]], lookup[arr[i]+1]);
                    lookup.erase(arr[i]);
                }
            }
            return res;
        }
};

int main (int argc, char *argv[]) {
    vector<vector<int>> v = {
        {1, 2, 3}, 
        {1, 1, 3, 3, 5, 5, 7, 7}, 
        {1, 1, 2, 2}, 
        {1, 3, 2, 3, 5, 0}, 
        {1, 1, 2}
    };
    Solution sol;
    for (int i = 0; i < v.size(); ++i) {
        cout << sol.countElements(v[i]) << "\n\n";
    }
    return 0;
}


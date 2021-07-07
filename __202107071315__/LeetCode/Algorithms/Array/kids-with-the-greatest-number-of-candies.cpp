#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(const vector<T> & vec) {
    copy(vec.begin(), vec.end(), ostream_iterator<T>(cout, " "));
    cout << "\n";
}

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = INT_MIN;
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > max) max = candies[i];
        }
        vector<bool> result(candies.size(), false);
        for (int i = 0; i < candies.size(); i++) {
            if ((candies[i] + extraCandies) >= max) result[i] = true;
        }
        return result;
    }
};

int main (int argc, const char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v1 = {2, 3, 5, 1, 3};
    Solution obj;
    print(obj.kidsWithCandies(v1, 3));

    vector<int> v2 = {4, 2, 1, 1, 2};
    vector<int> v3 = {12, 1, 12};
    print(obj.kidsWithCandies(v2, 1));
    print(obj.kidsWithCandies(v3, 10));

    return 0;
}


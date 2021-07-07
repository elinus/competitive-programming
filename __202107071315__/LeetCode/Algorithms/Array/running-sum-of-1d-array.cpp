#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(const vector<T> & vec) {
    copy(vec.begin(), vec.end(), ostream_iterator<T>(cout, " "));
    cout << "\n";
}

class Solution {
    public:
        vector<int> runningSum(vector<int> &nums) {
            for (int i = 1; i < nums.size(); ++i) {
                nums[i] += nums[i-1];
            }
            return nums;
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution obj;
    
    vector<int> v1 = {1, 2, 3, 4};
    print(obj.runningSum(v1));
    
    vector<int> v2 = {1, 1, 1, 1, 1};
    print(obj.runningSum(v2));
    
    vector<int> v3 = {3, 1, 2, 10,1};
    print(obj.runningSum(v3));

    return 0;
}

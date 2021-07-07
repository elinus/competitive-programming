#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  vector<int> createTargetArray(vector<int> &nums, vector<int> &index) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      result.insert(result.begin() + index[i], nums[i]);
    }
    return result;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);

  Solution soln;
  vector<int> nums1 = {0, 1, 2, 3, 4}, index1 = {0, 1, 2, 2, 1};
  print(soln.createTargetArray(nums1, index1));
  vector<int> nums2 = {1, 2, 3, 4, 0}, index2 = {0, 1, 2, 3, 0};
  print(soln.createTargetArray(nums2, index2));
  vector<int> nums3 = {1}, index3 = {0};
  print(soln.createTargetArray(nums3, index3));

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> copy(nums);
    sort(nums.begin(), nums.end());
    unordered_map<int, int> lookup;
    for (int i = 0; i < nums.size(); i++) {
      if (lookup.find(nums[i]) == lookup.end()) {
        lookup[nums[i]] = i;
      }
    }
    vector<int> result(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
      result[i] = lookup[copy[i]];
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
  vector<int> nums1 = {8, 1, 2, 2, 3};
  print(soln.smallerNumbersThanCurrent(nums1));
  vector<int> nums2 = {6, 5, 4, 8};
  print(soln.smallerNumbersThanCurrent(nums2));
  vector<int> nums3 = {7, 7, 7, 7};
  print(soln.smallerNumbersThanCurrent(nums3));

  return 0;
}

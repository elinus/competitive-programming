#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  vector<int> decompressRLElist(vector<int> &nums) {
    int size = 0;
    for (int i = 0; i < nums.size(); i = i + 2) {
      size += nums[i];
    }
    vector<int> v(size);
    int vi = 0;
    for (int i = 0; i < nums.size(); i = i + 2) {
      int freq = nums[i];
      int value = nums[i + 1];
      for (int fi = 0; fi < freq; fi++) {
        v[vi++] = value;
      }
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);

  Solution soln;
  vector<int> nums1 = {1, 2, 3, 4};
  print(soln.decompressRLElist(nums1));
  vector<int> nums2 = {1, 1, 2, 3};
  print(soln.decompressRLElist(nums2));

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
    int countDigits(int num) {
        int count = 0;
        while (num) {
            num /= 10;
            count++;
        }
        return count;
    }
public:
  int findNumbers(vector<int> &nums) {
      int count = 0;
      for (int i = 0; i < nums.size(); i++) {
          if (countDigits(nums[i]) % 2 == 0) count++;
      }
      return count;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);

  Solution soln;
  vector<int> nums1 = {12, 345, 2, 6, 7896};
  cout << soln.findNumbers(nums1) << "\n";
  vector<int> nums2 = {555, 901, 482, 1771};
  cout << soln.findNumbers(nums2) << "\n";
  return 0;
}

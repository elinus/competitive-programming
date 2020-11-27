#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    // int j = 0;
    // for (int i = 0; i < nums.size(); i++) {
    //   if (nums[i]) {
    //     nums[j++] = nums[i];
    //   }
    // }
    // for (int i = j; i < nums.size(); i++) {
    //   nums[i] = 0;
    // }
    
    //optimal
    for (int lz = 0, curr = 0; curr < nums.size(); curr++) {
        if (nums[curr]) {
            swap(nums[lz++], nums[curr]);
        }
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);

  Solution soln;
  vector<int> nums = {0, 1, 0, 3, 12};
  soln.moveZeroes(nums);
  print(nums);

  return 0;
}

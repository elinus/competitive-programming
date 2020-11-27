#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  int sumOddLengthSubarrays(vector<int> &arr) {
    int n = arr.size();
    int sum = 0;
    for (int onum = 1; onum <= n; onum = onum + 2) {
      for (int i = 0; i < n; i++) {
        for (int j = i; i + onum <= n && j < i + onum; j++) {
          sum += arr[j];
        }
      }
    }
    return sum;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);

  Solution soln;
  vector<int> arr1 = {1, 4, 2, 5, 3};
  cout << soln.sumOddLengthSubarrays(arr1) << "\n";
  vector<int> arr2 = {1, 2};
  cout << soln.sumOddLengthSubarrays(arr2) << "\n";
  vector<int> arr3 = {10, 11, 12};
  cout << soln.sumOddLengthSubarrays(arr3) << "\n";
  return 0;
}

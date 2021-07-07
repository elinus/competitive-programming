#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    if (digits.empty())
      return digits;
    reverse(digits.begin(), digits.end());
    if (digits.empty())
      return {1};
    int carry = 0;
    if ((digits[0] + 1) > 9) {
      carry = 1;
      digits[0] = 0;
    } else {
      digits[0] += 1;
    }
    for (int i = 1; carry && (i < digits.size()); i++) {
      if ((digits[i] + carry) > 9) {
        carry = 1;
        digits[i] = 0;
      } else {
        carry = 0;
        digits[i] += 1;
      }
    }
    if (carry)
      digits.push_back(1);

    reverse(digits.begin(), digits.end());
    return digits;
  }
};

int main() {
  chrono::time_point<chrono::high_resolution_clock> start, end;
  start = chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);

  Solution soln;
  /* Code */

  end = chrono::high_resolution_clock::now();
  const chrono::duration<double> elapsedTime = end - start;
  const double seconds = elapsedTime.count();
  cout << "time = " << seconds << " s.\n";
  return 0;
}

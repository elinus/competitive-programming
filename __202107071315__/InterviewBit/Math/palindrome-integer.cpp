#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

int /*Solution::*/ isPalindrome(int A) {
  if (A < 0)
    return false;
  string AStr = to_string(A);
  int n = AStr.size();
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (AStr[i] != AStr[j])
      return false;
  }
  return true;

  //   int rev = 0;
  //   while (A) {
  //     rev = 10 * rev + A % 10;
  //     A /= 10;
  //   }
  //   if (A == rev)
  //     return 1;
  //   else
  //     return 0;
}

int main() {
  chrono::time_point<chrono::high_resolution_clock> start, end;
  start = chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);

  //   Solution soln;
  /* Code */
  cout << isPalindrome(2147447412) << "\n";

  end = chrono::high_resolution_clock::now();
  const chrono::duration<double> elapsedTime = end - start;
  const double seconds = elapsedTime.count();
  cout << "time = " << seconds << " s.\n";
  return 0;
}

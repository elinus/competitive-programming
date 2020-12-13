#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  int stoneGameVII(vector<int> &stones) {
    int n = stones.size();
    int flip = false;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += stones[i];
    }
    int bob = 0, alice = 0;
    int i = 0, j = n - 1;
    while (i < j) {
      cout << i << ", " << j << "\n";
      int front_diff = sum - stones[i];
      int end_diff = sum - stones[j];
      int diff = front_diff > end_diff ? front_diff : end_diff;
      cout << "diff " << diff << "\n";
      if (front_diff < end_diff)
        sum -= stones[j--];
      else
        sum -= stones[i++];

      if (flip) { // bob
        bob += diff;
        flip = false;
      } else { // alice
        alice += diff;
        flip = true;
      }

      cout << "sum " << sum << "\n";
      cout << "A " << alice << ", B " << bob << "\n";
    }
    return alice - bob;
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
  vector<int> stones = {5, 3, 1, 4, 2} /* {7,90,5,1,100,10,10,2}*/;
  cout << soln.stoneGameVII(stones) << "\n";
  end = chrono::high_resolution_clock::now();
  const chrono::duration<double> elapsedTime = end - start;
  const double seconds = elapsedTime.count();
  cout << "time = " << seconds << " s.\n";
  return 0;
}

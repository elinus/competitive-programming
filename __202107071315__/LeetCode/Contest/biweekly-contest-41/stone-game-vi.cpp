#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues) {
    int aN = aliceValues.size(), bN = bobValues.size();

    sort(aliceValues.begin(), aliceValues.end());
    sort(bobValues.begin(), bobValues.end());
    int bob = 0, alice = 0;
    for (int i = 0; i < aN; i++) {
      if (aliceValues[i] > bobValues[i]) {
        alice++;
      } else if (aliceValues[i] < bobValues[i]) {
        bob++;
      }
    }
    if (alice > bob)
      return 1;
    if ((bob > alice) && (bob - alice == 1))
      return 0;
    else
      return -1;
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

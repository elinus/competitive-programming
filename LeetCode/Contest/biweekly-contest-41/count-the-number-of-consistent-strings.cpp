#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  int countConsistentStrings(string allowed, vector<string> &words) {

    int count = 0;
    if (allowed.length() == 0 || words.empty())
      return 0;
    vector<bool> alpha_lookup(26);
    for (int i = 0; i < allowed.length(); i++) {
      alpha_lookup[allowed[i] - 'a'] = true;
    }
    bool consistent = false;
    for (int i = 0; i < words.size(); i++) {
      consistent = true;
      for (int j = 0; j < words[i].length(); j++) {
        if (!alpha_lookup[words[i][j] - 'a']) {
          consistent = false;
          break;
        }
      }
      if (consistent) {
        count++;
      }
    }
    return count;
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

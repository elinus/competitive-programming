#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) {
      if (umap.find(target - nums[i]) != umap.end()) {
        return {umap[target - nums[i]], i};
      } else {
        umap[nums[i]] = i;
      }
    }
    return {};
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

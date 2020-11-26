class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    // frequency-counting strategy
    int map[101] = {};
    int numberOfPairs = 0;

    for (int i = 0; i < nums.size(); ++i) {
      ++map[nums[i]];
    }

    for (int i = 1; i <= 100; ++i) {
      if (map[i] > 1) {
        numberOfPairs += handshakeFormula(map[i]);
      }
    }

    return numberOfPairs;
  }

private:
  int handshakeFormula(
      int n) { // also see: https://en.wikipedia.org/wiki/Triangular_number
    return n * (n - 1) / 2;
  }
};
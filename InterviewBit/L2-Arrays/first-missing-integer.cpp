#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int> &A) {
  sort(A.begin(), A.end());
  int start = 0;
  while (A[start] != 1 && start < A.size())
    start++;
  if (start == A.size())
    return 1;
  else {
    for (int i = start + 1; i < A.size(); i++) {
      if (A[i] != A[i - 1] + 1)
        return A[i - 1] + 1;
    }
    return A[A.size() - 1] + 1;
  }
}
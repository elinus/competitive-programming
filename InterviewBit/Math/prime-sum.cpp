#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

bool isPrime(int n) {
  int sq_num = sqrt(n) + 1;
  for (int i = 2; i < sq_num; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

vector<int> primesum(int A) {
  for (int i = 2; i < 1 + A / 2; i++) {
    if (isPrime(i) && isPrime(A - i))
      return {i, A - i};
  }
  return {};
}

int main(int argc, char const *argv[]) {
  print(primesum(4));
  print(primesum(14));
  print(primesum(20));
  print(primesum(15));
  return 0;
}

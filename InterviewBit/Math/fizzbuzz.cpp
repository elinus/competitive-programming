#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, "\n"));
}

vector<string> fizzBuzz(int A) {
  vector<string> result(A);
  for (int i = 0; i < A; i++) {
    int num = i + 1;
    if ((num % 3) == 0 && (num % 5) == 0)
      result[i] = "FizzBuzz";
    else if ((num % 3) == 0)
      result[i] = "Fizz";
    else if ((num % 5) == 0)
      result[i] = "Buzz";
    else
      result[i] = to_string(num);
  }
  return result;
}

int main(int argc, char const *argv[]) {
  print(fizzBuzz(15));
  return 0;
}

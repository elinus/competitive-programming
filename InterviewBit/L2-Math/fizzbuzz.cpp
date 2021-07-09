#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<string> fizzBuzz(int A) {
  vector<string> arr(A);
  for (int i = 1; i <= A; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
      arr[i - 1] = "FizzBuzz";
    } else if (i % 3 == 0) {
      arr[i - 1] = "Fizz";
    } else if (i % 5 == 0) {
      arr[i - 1] = "Buzz";
    } else {
      arr[i - 1] = to_string(i);
    }
  }
  return arr;
}

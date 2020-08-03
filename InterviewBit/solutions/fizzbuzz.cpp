#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> fizzbuzz(int A) {
    std::vector<std::string> res(A);
    for(int i = 1; i <= A; ++i) {
        if (i % 15 == 0) {
            res[i-1] = "FizzBuzz";
        } else if (i % 5 == 0) {
            res[i-1] = "Buzz";
        } else if (i % 3 == 0) {
            res[i-1] = "Fizz";
        } else {
            res[i-1] = std::to_string(i);
        }
    }
    return res;
}

void print(const std::vector<std::string> & v) {
    for(std::string s: v) {
        std::cout << s << "\n";
    }
}

int main (int argc, char *argv[]) {
    std::vector<std::string> v1 = fizzbuzz(3);
    print(v1);
    return 0;
}


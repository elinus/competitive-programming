#include <iostream>

class Solution {
    public:
        bool isHappy(int n) {
            while (true) {
                int sum = 0;
                while (n) {
                    int rem = n % 10;
                    n /= 10;
                    sum += (rem * rem);
                }
                if (sum > 0 && sum < 10) {
                    if (sum == 1 || sum == 7) return true;
                    else return false;
                }
                n = sum;
            }
        }
};

int main (int argc, char *argv[]) {
    Solution sol;
    int n {0};
    std::cin >> n;
    std::cout << sol.isHappy(n) << "\n";
    return 0;
}


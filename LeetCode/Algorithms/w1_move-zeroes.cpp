#include <iostream>
#include <vector>

class Solution {
    public:
        void moveZeroes(std::vector<int> & nums) {
            int j = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i]) {
                    nums[j++] = nums[i];
                }
            }
            for (int i = j; i < nums.size(); i++) {
                nums[i] = 0;
            }
        }
};

void print(const std::vector<int> & v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main (int argc, char *argv[]) {
    Solution sol;
    std::vector<int> v1 = {0, 1, 0, 3, 12};
    print(v1);
    sol.moveZeroes(v1);
    print(v1);
    return 0;
}


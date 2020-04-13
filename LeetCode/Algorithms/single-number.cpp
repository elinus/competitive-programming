#include <iostream>
#include <vector>

class Solution {
    public:
        int singleNumber(std::vector<int> & nums) {
            auto x = 0;
            for (auto i = 0; i < nums.size(); i++) {
                x ^= nums[i];
            }
            return x;
        }
};

int main (int argc, char *argv[]) {
    std::vector<int> v1 = {2, 2, 1, 4, 1};
    Solution sol;
    std::cout << sol.singleNumber(v1) << "\n";
    return 0;
}


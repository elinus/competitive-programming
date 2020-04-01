#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
    public:
        int findDuplicate(std::vector<int> & nums) {
            std::unordered_set<int> uset;
            for (auto i = 0; i < nums.size(); i++) {
                if (uset.find(nums[i]) == uset.end()) {
                    uset.insert(nums[i]);
                } else {
                    return nums[i];
                }
            }
            return 0;
        }
};

int main (int argc, char *argv[]) {
    std::vector<int> v = {5, 5, 3, 4, 2};
    Solution sol;
    std::cout << sol.findDuplicate(v) << "\n";
    return 0;
}


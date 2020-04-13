#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int> & nums) {
        long long int n = nums.size();
        long long int expected_sum = n * (n + 1) / 2;
        long long int actual_sum = 0;
        for (int i = 0; i < n; i++) {
            actual_sum += nums[i];
        }
        return static_cast<int>(expected_sum - actual_sum);
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> v1 = {9,6,4,2,3,5,7,0,1};
    Solution soln;
    std::cout << soln.missingNumber(v1) << "\n";
    return 0;
}


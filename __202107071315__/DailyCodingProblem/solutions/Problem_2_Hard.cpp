#include <iostream>
#include <vector>

std::vector<int> Solution(const std::vector<int> & nums) {
    auto n = nums.size();
    std::vector<int> left(n);
    std::vector<int> right(n);
    std::vector<int> result(n);

    left[0] = 1;
    for (int i = 1; i < n; i++) {
        left[i] = left[i-1] * nums[i-1];
    }
    
    right[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        right[i] = right[i+1] * nums[i+1];
    }

    for (int i = 0; i < n; i++) {
        result[i] = left[i] * right[i];
    }

    return result;
}

int main (int argc, char *argv[]) {

    auto res1 = Solution({3, 2, 1}); 
    for (const int & x : res1) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    auto res2 = Solution({1, 2, 3, 4, 5}); 
    for (const int & x : res2) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    
    return 0;
}


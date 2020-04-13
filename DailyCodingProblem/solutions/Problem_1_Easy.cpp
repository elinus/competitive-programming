#include <iostream>
#include <unordered_set>
#include <vector>
#include <cassert>

bool Solution(const std::vector<int> & nums, int k) {
    std::unordered_set<int> hash;

    auto n = nums.size();
    auto itr_hash = hash.begin();

    for (auto i = 0; i < n; i++) {
        itr_hash = hash.find(nums[i]);
        if (itr_hash != hash.end())
            return true;
        hash.insert(k - nums[i]);
    }

    return false;
}

int main (int argc, char *argv[]) {
    
    assert(Solution({10, 15, 3, 7}, 17) == true);
    assert(Solution({}, 17) == false);
    assert(Solution({10, 15, 3, 4}, 17) == false);

    return 0;
}


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count_map;
        for (auto i = 0; i < nums.size(); ++i) {
            if (count_map.find(nums[i]) != count_map.end()) {
                count_map[nums[i]] += 1;
            } else {
                count_map[nums[i]] = 1;
            }
        }
        int result = 0;
        for (auto it = count_map.begin(); it != count_map.end(); ++it) {
            if (it->second > (nums.size()/2)) {
                result = it->first;
            }
        }
        return result;
    }
};

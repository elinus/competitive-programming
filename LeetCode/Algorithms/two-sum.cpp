class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap_;
        int i = -1, j = -1; 
        for (int k = 0; k < nums.size(); ++k) {
            auto it = umap_.find(target - nums[k]);
            if (it != umap_.end()) {
                i = it->second;
                j = k;
                break;
            } else {
                umap_[nums[k]] = k;
            }
        }
        
        return {i, j};
    }
};

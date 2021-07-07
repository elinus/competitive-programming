class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int k = 1;
        int last = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == last) continue;
            else {
                last = nums[i];
                nums[k++] = nums[i];
            }
        }
        nums.resize(k);
        return k;
    }
};

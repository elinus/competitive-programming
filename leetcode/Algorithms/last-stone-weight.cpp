class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()) return 0;
        int n = stones.size();
        if (n == 1) return stones[0];
        
        while (!stones.empty() && n > 1) {
            // for(int i = 0; i < n; ++i) cout << stones[i] << " ";
            // cout << "\n";
            
            sort(stones.begin(), stones.end());
            int diff = stones[n-1] - stones[n-2];
            if (diff == 0) {
                stones.resize(n-2);
                n -= 2;
            } else {
                stones[n-2] = diff;
                stones.resize(n-1);
                n -= 1;
            }
        }
        if (stones.empty()) return 0;
        return stones[0];
    }
};

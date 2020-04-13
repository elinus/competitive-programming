#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int max_profit = 0; 
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] > prices[i-1]) {
                    max_profit += (prices[i] - prices[i-1]);
                }
            }
            return max_profit;
        }
};

int main (int argc, char *argv[]) {
    vector<int> v1 = {7, 5};
    Solution sol;
    cout << sol.maxProfit(v1) << "\n";
    return 0;
}


#include <bits/stdc++.h>

using namespace std;
class Solution {
    int mRow, mCol;
    // vector<int> rowNbr = { 1, 0 }; 
    // vector<int> colNbr = { 0, 1 };
    // bool safe(int row, int col) {
    //     if (row >= 0 && row < mRow && col >= 0 && col < mCol)
    //         return true;
    //     return false;
    // }
    // void dfs(int row, int col, 
    //         const vector<vector<int>>& grid, 
    //         vector<vector<int>>& visited, 
    //         int& min_dist, int dist) {
    //     if (row == mRow-1 && col == mCol-1) {
    //         min_dist = min(min_dist, dist);
    //         return;
    //     }
    //     visited[row][col] = 1; 
    //     if (safe(row + 1, col)) {
    //         dfs(row + 1, col, grid, visited, min_dist, dist + grid[row + 1][col]);
    //     }
    //     if (safe(row, col+1)) {
    //         dfs(row, col + 1, grid, visited, min_dist, dist + grid[row][col + 1]);
    //     }
    //     visited[row][col] = 0; 
    // }
    // int min(int x, int y, int z) { 
    //     if (x < y) 
    //         return (x < z)? x : z; 
    //     else
    //         return (y < z)? y : z; 
    // } 
    public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        mRow = grid.size();
        mCol = grid[0].size();
        // int min_dist = INT_MAX;
        // vector<vector<int>> visited(mRow, vector<int>(mCol, 0));
        // dfs(0, 0, grid, visited, min_dist, grid[0][0]);
        // return min_dist;
        
        vector<vector<int>> dp(mRow, vector<int>(mCol, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < mRow; i++) 
            dp[i][0] = dp[i-1][0] + grid[i][0]; 
        for (int j = 1; j < mCol; j++) 
            dp[0][j] = dp[0][j-1] + grid[0][j]; 
        for (int i = 1; i < mRow; i++) 
            for (int j = 1; j < mCol; j++) 
                dp[i][j] = grid[i][j] + min(dp[i-1][j],  dp[i][j-1]); 
  
     return dp[mRow - 1][mCol - 1]; 
    }
};

int main (int argc, char *argv[]) {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 3, 1}, 
        {1, 5, 1},
        {4, 2, 1}};
    cout << sol.minPathSum(grid) << "\n"; 
    return 0;
}



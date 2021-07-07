class Solution {
    int mRow, mCol;
    vector<int> rowNbr = { 1, 0, -1, 0 }; 
    vector<int> colNbr = { 0, 1, 0, -1 };
    bool safe(int row, int col, const vector<vector<char>>& grid, const vector<vector<char>>& visited) {
        if (row >= 0 && row < mRow && col >= 0 && col < mCol && visited[row][col] != '1' && grid[row][col] == '1')
            return true;
        return false;
    }
    void dfs(int row, int col, const vector<vector<char>>& grid, vector<vector<char>>& visited) {
        visited[row][col] = '1'; 
        for (int k = 0; k < 4; ++k) {
            if (safe(row + rowNbr[k], col + colNbr[k], grid, visited)) {
                dfs(row + rowNbr[k], col + colNbr[k], grid, visited);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        mRow = grid.size();
        mCol = grid[0].size();
        int island_count = 0;
        vector<vector<char>> visited(mRow, vector<char>(mCol, '0'));
        for (int i = 0; i < mRow; ++i) {
            for (int j = 0; j < mCol; ++j)  {
                if (grid[i][j] == '1' && visited[i][j] != '1') {
                    dfs(i, j, grid, visited);
                    island_count++;
                }
            }
        }
        return island_count;
    }
};

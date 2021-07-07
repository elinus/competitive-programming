class Solution {
    int mRow, mCol;
    vector<int> rowNbr = { 1, 0, -1, 0 }; 
    vector<int> colNbr = { 0, 1, 0, -1 };
    bool safe(int row, int col, const vector<vector<int>>& grid/*, const vector<vector<int>>& visited*/) {
        if (row >= 0 && row < mRow && col >= 0 && col < mCol /*&& !visited[row][col]*/ && grid[row][col])
            return true;
        return false;
    }
    // void dfs(int row, int col, const vector<vector<int>>& grid, vector<vector<int>>& visited) {
    //     visited[row][col] = 1; 
    //     for (int k = 0; k < 4; ++k) {
    //         if (safe(row + rowNbr[k], col + colNbr[k], grid, visited)) {
    //             dfs(row + rowNbr[k], col + colNbr[k], grid, visited);
    //         }
    //     }
    // }
    int countOne(int row, int col, const vector<vector<int>>& grid) {
        int one = 0;
        for (int k = 0; k < 4; ++k) {
            if (safe(row + rowNbr[k], col + colNbr[k], grid)) {
                one++;
            }
        }
        return one;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        mRow = grid.size();
        mCol = grid[0].size();
        int perimeter = 0;
        //vector<vector<int>> visited(mRow, vector<int>(mCol, 0));
        for (int i = 0; i < mRow; ++i) {
            for (int j = 0; j < mCol; ++j)  {
                if (grid[i][j] /*&& !visited[i][j]*/) {
                    perimeter += (4 - countOne(i, j, grid/*, visited*/));
                }
            }
        }
        return perimeter;
    }
};


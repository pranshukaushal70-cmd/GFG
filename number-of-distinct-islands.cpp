class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid,
             vector<pair<int,int>>& shape, int baseRow, int baseCol) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        shape.push_back({row - baseRow, col - baseCol});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && grid[nrow][ncol] == 'L' && !vis[nrow][ncol]) {
                dfs(nrow, ncol, vis, grid, shape, baseRow, baseCol);
            }
        }
    }
public:
    int countDistinctIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> st;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == 'L') {
                    vector<pair<int,int>> shape;
                    dfs(row, col, vis, grid, shape, row, col);
                    st.insert(shape);
                }
            }
        }
        return st.size();
    }
};

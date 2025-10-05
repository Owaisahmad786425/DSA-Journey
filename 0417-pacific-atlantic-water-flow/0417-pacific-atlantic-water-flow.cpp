class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& ocean) {
        ocean[r][c] = true;
        for (auto &d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n || ocean[nr][nc]) continue;
            if (heights[nr][nc] >= heights[r][c])
                dfs(nr, nc, heights, ocean);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

     
        for (int i = 0; i < m; ++i) dfs(i, 0, heights, pac);
        for (int j = 0; j < n; ++j) dfs(0, j, heights, pac);

 
        for (int i = 0; i < m; ++i) dfs(i, n - 1, heights, atl);
        for (int j = 0; j < n; ++j) dfs(m - 1, j, heights, atl);

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pac[i][j] && atl[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};

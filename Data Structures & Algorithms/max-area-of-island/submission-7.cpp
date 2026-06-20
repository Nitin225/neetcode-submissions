class Solution {
public:
    int mArea = 0;
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis, int& area){
        vis[r][c] = 1;
        area++;
        mArea = max(mArea, area);

        int n = grid.size();
        int m = grid[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                dfs(nrow, ncol, grid, vis, area);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        mArea = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(!vis[i][j] && grid[i][j]==1){
                    int area = 0;
                    dfs(i, j, grid, vis, area);
                }

        return mArea;
    }
};
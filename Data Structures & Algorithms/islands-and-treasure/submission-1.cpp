class Solution {
public:
    void dfs(int row, int col, int dist, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        if(row<0 || row>=n || col<0 || col>=m) return;
        if(grid[row][col] == -1) return;
        if(grid[row][col] < dist) return;  // already shorter path hai
        
        grid[row][col] = dist;
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++)
            dfs(row+drow[i], col+dcol[i], dist+1, grid);
    }

    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 0)
                    dfs(i, j, 0, grid);
    }
};

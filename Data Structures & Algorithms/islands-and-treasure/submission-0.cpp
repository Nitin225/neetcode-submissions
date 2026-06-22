class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0)
                    q.push({{i,j},0});
            }
        }
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 2147483647){
                    q.push({{nrow,ncol},dist+1});
                    grid[nrow][ncol] = dist + 1;
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
};

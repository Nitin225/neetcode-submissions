class Solution {
private:
    void bfs(int n, int m, queue<pair<int,int>> &q, vector<vector<bool>> &vis, vector<vector<int>> &heights){

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int nr= r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    q.push({nr,nc});
                    vis[nr][nc] = true;
                }
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;

        vector<vector<bool>> vis1(n, vector<bool>(m, false));
        vector<vector<bool>> vis2(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0){
                    q1.push({i,j});
                    vis1[i][j] = true;
                }
                if(i==n-1 || j==m-1){
                    q2.push({i,j});
                    vis2[i][j] = true;
                }

            }
        }

        bfs(n, m, q1, vis1, heights);
        bfs(n, m, q2, vis2, heights);

        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis1[i][j] && vis2[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};

class Solution {
private:
    void bfs(int n, int m, queue<pair<int,int>> &q1, vector<vector<bool>> &vis1, vector<vector<int>> &heights){

        while(!q1.empty()){
            int r1 = q1.front().first;
            int c1 = q1.front().second;
            q1.pop();

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int nr1 = r1 + drow[i];
                int nc1 = c1 + dcol[i];

                if(nr1>=0 && nr1<n && nc1>=0 && nc1<m && !vis1[nr1][nc1] && heights[nr1][nc1] >= heights[r1][c1]){
                    q1.push({nr1,nc1});
                    vis1[nr1][nc1] = true;
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

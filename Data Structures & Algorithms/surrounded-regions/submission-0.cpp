class Solution {
public:

    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        board[row][col] = '#';

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, -1, 0, 1};

        for(int i=0; i<4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && board[nRow][nCol] == 'O')
                dfs(nRow, nCol, board, vis);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || i==n-1) || (j==0 || j==m-1)){
                    if(board[i][j] == 'O')
                        dfs(i, j, board, vis);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';  // surrounded wale
                if(board[i][j] == '#') board[i][j] = 'O';  // boundary wale safe
            }
        }
    }
};

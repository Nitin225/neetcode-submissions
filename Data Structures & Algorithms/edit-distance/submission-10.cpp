class Solution {
private:
    int helper(int n, int m, string &word1, string &word2, vector<vector<int>> &dp){
        if(n < 0)
            return m + 1;

        if(m < 0)
            return n + 1;

        if(dp[n][m] != -1) return dp[n][m];

        if(word1[n] == word2[m])
            return helper(n-1, m-1, word1, word2, dp);
        else
            return dp[n][m] = 1 + min({helper(n, m-1, word1, word2, dp),
                    helper(n-1, m, word1, word2, dp),
                    helper(n-1, m-1, word1, word2, dp)});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // return helper(n-1, m-1, word1, word2, dp);
        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=0; j<=m; j++) dp[0][j] = j;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
        }
        return dp[n][m];
    }
};

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

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(n-1, m-1, word1, word2, dp);
    }
};

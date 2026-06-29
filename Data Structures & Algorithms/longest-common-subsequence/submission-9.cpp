class Solution {
private:
    int helper(int n, int m, string s1, string s2, vector<vector<int>> &dp){
        if(n < 0 || m < 0)
            return 0;

        if(dp[n][m] != -1) return dp[n][m];

        if(s1[n] == s2[m]) 
            return dp[n][m] = 1 + helper(n-1, m-1, s1, s2, dp);

        return dp[n][m] = max(helper(n-1, m, s1, s2, dp), helper(n, m-1, s1, s2, dp));
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n-1, m-1, s1, s2, dp);
    }
};

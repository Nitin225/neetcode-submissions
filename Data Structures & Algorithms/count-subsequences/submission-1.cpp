class Solution {
private:
    int helper(int n, int m, string s, string t, vector<vector<long long>> &dp){
        if(m == 0) return 1;
        if(n == 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        if(s[n-1] == t[m-1]) 
            return dp[n][m] = helper(n-1, m-1, s, t, dp) + helper(n-1, m, s, t, dp);
        else
            return dp[n][m] = helper(n-1, m, s, t, dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<long long>> 
        dp(n+1, vector<long long>(m+1, -1));
        return helper(n, m, s, t, dp);

        
    }
};
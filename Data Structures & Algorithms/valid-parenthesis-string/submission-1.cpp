class Solution {
private:
    bool helper(string s, int n, int a, vector<vector<int>> &dp){
        if(n < 0)
            return a == 0;
        
        if (a < 0)
            return false;

        if(dp[n][a] != -1) return dp[n][a];

        bool ans = false;

        if(s[n] == ')')
            ans = helper(s, n-1, a+1, dp);
        if(s[n] == '(')
            ans = helper(s, n-1, a-1, dp);

        if(s[n] == '*'){
            ans = helper(s, n-1, a+1, dp) || 
            helper(s, n-1, a-1, dp) || 
            helper(s, n-1, a, dp);
        }

        return dp[n][a] = ans;
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(s, n-1, 0, dp);
    }
};

class Solution {
private:
    int helper(int i, int buy, int n, vector<int> &prices, vector<vector<int>> &dp){
        if(i >= n) return 0;
        int profit = 0;

        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
            profit = max(-prices[i] + helper(i+1, 0 ,n ,prices, dp),
            helper(i+1, 1, n, prices, dp));
        }
        else {
            profit = max(prices[i] + helper(i+2, 1 ,n ,prices, dp),
            helper(i+1, 0, n, prices, dp));
        }

        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return helper(0, 1, n, prices, dp);
    }
};

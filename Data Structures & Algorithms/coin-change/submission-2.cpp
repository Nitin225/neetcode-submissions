class Solution {
private:
    int helper(int n, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if (n == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }
        if(dp[n][amount] != -1) return dp[n][amount];

        int notTake = helper(n - 1, coins, amount, dp);

        int take = 1e9;
        if (coins[n] <= amount)
            take = 1 + helper(n, coins, amount - coins[n], dp);

        return dp[n][amount] = min(take, notTake);

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = helper(n-1, coins, amount, dp);

        if (ans >= 1e9)
            return -1;

        return ans;

    }
};

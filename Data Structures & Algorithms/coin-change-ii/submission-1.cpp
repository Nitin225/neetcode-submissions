class Solution {
private:
    int helper(int n, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if (n == 0) {
            if (amount % coins[0] == 0)
                return 1;
            return 0;
        }
        if(dp[n][amount] != -1) return dp[n][amount];

        int notTake = helper(n - 1, coins, amount, dp);

        int take = 0;
        if (coins[n] <= amount)
            take = helper(n, coins, amount - coins[n], dp);

        return dp[n][amount] = take + notTake;

    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // return helper(n-1, coins, amount, dp);

        for(int j=0; j<=amount; j++){
            dp[0][j] = (j % coins[0] == 0);
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                int notTake = dp[i - 1][j];

                int take = 0;
                if (coins[i] <= j)
                    take = dp[i][j-coins[i]];

                dp[i][j] = take + notTake;
            }
        }
        return dp[n-1][amount];

    }
};

class Solution {
private:
    int helper(int n, vector<int> &coins, int amount){
        if (n == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }

        
        int notTake = helper(n - 1, coins, amount);

        int take = 1e9;
        if (coins[n] <= amount)
            take = 1 + helper(n, coins, amount - coins[n]);

        return min(take, notTake);

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int ans = helper(n-1, coins, amount);

        if (ans >= 1e9)
            return -1;

        return ans;

    }
};

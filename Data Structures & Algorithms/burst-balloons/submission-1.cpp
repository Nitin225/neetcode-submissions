class Solution {
private:
    int helper(int i, int j, vector<int>& nums, vector<vector<int>> &dp){
        if(i > j) return 0;
        int mini = -1e9;

        if(dp[i][j] != -1) return dp[i][j];

        for(int ind=i; ind<=j; ind++){
            int coins = nums[i-1] * nums[ind] * nums[j+1]+
            helper(i, ind-1, nums, dp) +
            helper(ind+1, j, nums, dp);

            mini = max(mini, coins);
        }
        return dp[i][j] = mini;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(1, n, nums, dp);
    }
};

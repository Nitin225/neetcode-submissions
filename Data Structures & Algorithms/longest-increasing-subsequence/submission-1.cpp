class Solution {
private:
    int helper(int n, int last, vector<int>& nums, vector<vector<int>> &dp){
        if(n < 0)
            return 0;

        if(dp[n][last+1] != -1) return dp[n][last+1];

        int notPick = helper(n-1, last, nums, dp);

        int pick = 0;
        if(last == -1 || nums[n] < nums[last]){
            pick = 1 + helper(n-1, n, nums, dp);
        }

        return dp[n][last+1] = max(notPick, pick);
        

    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return helper(n-1, -1, nums, dp);
        
    }
};

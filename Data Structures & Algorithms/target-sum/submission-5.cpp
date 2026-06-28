class Solution {
private:
    int helper(int n, int sum, vector<int> &nums, vector<vector<int>> &dp){
    if(n == 0){
        if(sum == 0 && nums[0] == 0)
            return 2;

        if(sum == 0 || nums[0] == sum)
            return 1;

        return 0;
    }
    if(dp[n][sum] != -1)
        return dp[n][sum];
    
    int notPick = helper(n-1, sum, nums, dp);
    int pick = 0;
    if(nums[n] <= sum)
        pick = helper(n-1, sum-nums[n], nums, dp);
    
    return dp[n][sum] = notPick + pick; 
}

int CountSubarrayWithKSum(vector<int> &nums, int sum){
    
}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = accumulate(nums.begin(), nums.end(), 0);

        if(totSum - target < 0 || (totSum - target) % 2) return 0;
        int sum = (totSum-target)/2;
        
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return helper(n-1, sum, nums, dp);
    }
};

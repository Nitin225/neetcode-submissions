class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum = 0;
        for(int x: nums){
            totSum += x;
        }
        
        if(totSum < abs(target)) return 0;
        if((totSum - target) % 2 != 0) return 0;
        int sum = (totSum - target) / 2;
    
       
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }
        dp[0][0] = (nums[0] == 0) ? 2 : 1;

        if(nums[0] != 0 && nums[0] <= sum)
                dp[0][nums[0]] = 1;

        for(int i=1; i<n; i++){
            for(int target=0; target<=sum; target++){
                
                int notPick = dp[i-1][target];
                int pick = 0;
                if(nums[i] <= target) pick = dp[i-1][target-nums[i]];

                dp[i][target] = pick + notPick;
            }
        }
        return dp[n-1][sum];
    }
};

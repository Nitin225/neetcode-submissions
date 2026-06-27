class Solution {
public:
    bool help(int n, int hsum, vector<int>& nums, vector<vector<int>> &dp){
        if(hsum == 0)
            return true;
        
        if(n == 0) 
            return nums[0] == hsum;

        if(dp[n][hsum] != -1)
            return dp[n][hsum];

        bool notTake = help(n-1, hsum, nums, dp);
        bool take = false;
        if(hsum >= nums[n]){
            take = help(n-1, hsum-nums[n], nums, dp);
        }

        return dp[n][hsum] =  notTake || take;

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x: nums){
            sum = sum + x;
        }
        int hsum = sum/2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(hsum + 1, 0));

        if(sum % 2 != 0) return false;
        // if(help(n-1, hsum, nums, dp))
        //     return true;
        // else return false;

        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        if (nums[0] <= hsum)
            dp[0][nums[0]] = true;

        for(int i=1; i<n; i++){
            for(int target=1; target<=hsum; target++){
                bool notTake = dp[i-1][target];
                bool take = false;
                if(target >= nums[i]){
                    take = dp[i-1][target-nums[i]];
                }
                dp[i][target] = take || notTake;
            }
        }
        return dp[n-1][hsum];



    }
};
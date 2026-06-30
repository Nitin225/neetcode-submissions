class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
        for (int index = 0; index < n; index++)
            dp[0][index + 1] = 0;

        for (int index = 0; index <= n; index++)
            dp[index][0] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int last = ind - 1; last >= -1; last--) {
                int notPick = dp[ind + 1][last + 1];
                int pick = 0;
                if (last == -1 || nums[ind] > nums[last]) {
                    pick = 1 + dp[ind + 1][ind + 1];
                }
                dp[ind][last + 1] = max(pick, notPick);
            }
        }
        return dp[0][0];  
    }
};

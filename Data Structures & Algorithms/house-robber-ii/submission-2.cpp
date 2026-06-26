class Solution {
private: 
    int helper(vector<int> nums){
        int n = nums.size()-1;
        if(n == 0) return nums[0];
        if(n == 1) return max(nums[0], nums[1]);

        vector<int> dp(n+1,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n+1; i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1(nums.begin()+1, nums.end()),
        temp2(nums.begin(), nums.end()-1);

        return max(helper(temp1), helper(temp2));
    }
};

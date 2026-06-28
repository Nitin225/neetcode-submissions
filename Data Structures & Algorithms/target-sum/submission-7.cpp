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
        vector<int> prev(sum+1, 0), curr(sum+1, 0);

        for(int i=0; i<n; i++){
            prev[0] = 1;
        }
        prev[0] = (nums[0] == 0) ? 2 : 1;

        if(nums[0] != 0 && nums[0] <= sum)
                prev[nums[0]] = 1;

        for(int i=1; i<n; i++){
            for(int target=0; target<=sum; target++){
                
                int notPick = prev[target];
                int pick = 0;
                if(nums[i] <= target) pick = prev[target-nums[i]];

                curr[target] = pick + notPick;
            }
            prev = curr;
        }
        return prev[sum];
    }
};

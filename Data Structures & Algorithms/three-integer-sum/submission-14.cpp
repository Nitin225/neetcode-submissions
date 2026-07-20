class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0;
        int n = nums.size();
        vector<vector<int>> ans;
        while(i < n){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int z = nums[i] + nums[j] + nums[k];
                if(z == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j-1] == nums[j]) j++;
                    while(j < k && nums[k+1] == nums[k]) k--;
                }
                else if(z < 0) j++;
                else k--;
            }
            i++;
            while(i < n && nums[i-1] == nums[i])
                i++;
        }
        return ans;
    }
};

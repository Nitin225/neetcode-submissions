class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            unordered_set<int> seen;
            for(int j=i+1; j<n; j++){
                int need = -nums[i] - nums[j];
                if(seen.count(need)){
                    ans.push_back({nums[i], nums[j], need});
                    while(j+1 < n && nums[j] == nums[j+1]) j++;
                }
                seen.insert(nums[j]);
            }
        }
        return ans;
    }
};

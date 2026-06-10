class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int mx = 0;
        for(int i=0; i<nums.size()-k+1; i++){
            mx = nums[i];
            for(int j=i; j<i+k; j++){
                mx = max(mx, nums[j]);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};

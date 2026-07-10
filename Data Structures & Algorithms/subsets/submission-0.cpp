class Solution {
private:    
    void helper(int i, int n, vector<int> v, vector<int> &nums, vector<vector<int>> &ans){
        if(i == n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        helper(i+1, n, v, nums, ans);
        v.pop_back();
        helper(i+1, n, v, nums, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        helper(0, n, v, nums, ans);
        return ans;
    }
};

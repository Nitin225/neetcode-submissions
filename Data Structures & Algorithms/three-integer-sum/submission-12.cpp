class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st1;
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            unordered_set<int> st;
            for(int j=i+1; j<n; j++){
                int rem = nums[i] + nums[j];
                if(st.count(-rem)){
                    vector<int> temp = {nums[i], -rem, nums[j]};
                    sort(temp.begin(), temp.end());
                    st1.insert(temp);
                }
                else
                    st.insert(nums[j]);
            }
        }
        for(auto x : st1)
            ans.push_back(x);
        return ans;
    }
};

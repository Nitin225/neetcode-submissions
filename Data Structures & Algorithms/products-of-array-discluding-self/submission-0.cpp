class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        int n = nums.size();
        int pl = 1;
        left.push_back(1);
        for(int i=0; i<n-1; i++){
            pl *= nums[i];
            left.push_back(pl);
        }
        int pr = 1;
        right.push_back(1);
        for(int i=0; i<n-1; i++){
            pr *= nums[n-i-1];
            right.push_back(pr);
        }
        reverse(right.begin(), right.end());

        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(left[i]*right[i]);
        }
        return ans;
    }
};

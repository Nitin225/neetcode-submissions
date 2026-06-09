class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int st = i+1;
            int end = n-1;
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            while(st < end){
                int sum = nums[i] + nums[st] + nums[end];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[st], nums[end]});
                    st++;
                    end--;
                    while(st<end && nums[st] == nums[st-1])
                        st++;
                    while(st<end && nums[end] == nums[end+1])
                        end--;
                }
                else if(sum < 0)
                    st++;
                else
                    end--;
            }
        }
        return ans;
    }
};

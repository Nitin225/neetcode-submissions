class Solution {
public:
    vector<int> nse(vector<int> &nums){
        stack<int> st;
        int n = nums.size();
        vector<int> nse(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[i] <= nums[st.top()])
                st.pop();
            
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            
            st.push(i);
        }
        return nse;
    }

    vector<int> pse(vector<int> &nums){
        stack<int> st;
        int n = nums.size();
        vector<int> pse(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[i] <= nums[st.top()])
                st.pop();
            
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& nums) {
        vector<int> Pse = pse(nums);
        vector<int> Nse = nse(nums);
        int area = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            area = max(area, nums[i]*(Nse[i]-Pse[i]-1));
        }
        return area;
    }
};

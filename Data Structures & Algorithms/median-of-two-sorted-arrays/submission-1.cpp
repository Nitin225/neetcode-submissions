class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for(int x: nums1)
            nums.push_back(x);

        for(int x: nums2)
            nums.push_back(x);

        sort(nums.begin(), nums.end());

        int mid = (nums.size()-1)/2;
        if(nums.size() % 2 == 0)
            return (double)(nums[mid] + nums[mid+1])/2;
        else return (double)nums[mid];
    }
};

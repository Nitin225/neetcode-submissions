class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int m = nums1.size();
        int n = nums2.size();
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]){
                nums.push_back(nums2[j]);
                j++;
            }
            else{
                nums.push_back(nums1[j]);
                nums.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        while(i<m){
            nums.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            nums.push_back(nums2[j]);
            j++;
        }

        int mid = (m+n-1)/2;
        if(nums.size() % 2 == 0)
            return (double)(nums[mid] + nums[mid+1])/2;
        return (double)nums[mid];
    }
};

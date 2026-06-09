class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l, r, total, lMax, rMax;
        l = total = lMax = rMax = 0;
        r = n-1;

        vector<int> prefix(n,0);
        while(l < r) {
            if(height[l] < height[r]){
                if(lMax > height[l]){
                    total += lMax - height[l];
                } else {
                    lMax = height[l];
                }
                l++;
            } else {
                if(rMax > height[r]){
                    total += rMax - height[r];
                } else {
                    rMax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};

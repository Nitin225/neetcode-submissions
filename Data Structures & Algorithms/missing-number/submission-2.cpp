class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int Asum = 0;
        if(n % 2 == 0)
            Asum = n/2 * (n+1);
        else
            Asum = n * (n+1)/2;
        
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        int ans = Asum - sum;
        if(ans > 0) return ans;
        else return 0;

    }
};

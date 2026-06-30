class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));

        int profit = 0;
        vector<int> ahead(2, 0), curr(2, 0);
        ahead[0] = ahead[1] = 0;
        for(int i=n-1; i>=0; i--){
               
        dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
    
        dp[i][0] = max(prices[i] + dp[i+2][1], dp[i+1][0]);
                
        }

        
        return dp[0][1];


    }
};

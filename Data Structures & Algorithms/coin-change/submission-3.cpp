class Solution {    
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1), curr(amount + 1);

        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                prev[target] = target / coins[0];
            else
                prev[target] = 1e9;
        }

        for(int i=1; i<n; i++){
            for(int target=1; target<=amount; target++){
                int notTake = prev[target];

                int take = 1e9;
                if (coins[i] <= target)
                    take = 1 + curr[target - coins[i]];

                curr[target] = min(take, notTake);
            }
            prev = curr;
        }
        if (prev[amount] >= 1e9)
            return -1;

        return prev[amount];

    }
};

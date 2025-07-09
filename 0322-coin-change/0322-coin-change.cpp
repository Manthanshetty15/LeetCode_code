class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0)
                dp[0][t] = t / coins[0];
        }

        for(int ind = 1; ind < n; ind++) {
            for(int t = 0; t <= amount; t++) {
                int nottake = dp[ind - 1][t];
                int take = 1e9;
                if(coins[ind] <= t)
                    take = 1 + dp[ind][t - coins[ind]];
                dp[ind][t] = min(take, nottake);
            }
        }

        return (dp[n - 1][amount] >= 1e9) ? -1 : dp[n - 1][amount];
    }
};

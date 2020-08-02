class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();

        if (k < days / 2) {
            int dp[days+1][k+1][2];

            for (int i = 0; i < k+1; ++i) {
                dp[0][i][0] = 0;
                dp[0][i][1] = INT_MIN;
            }

            for (int i = 1; i <= days; ++i) {
                for (int j = 0; j <= k; ++j) {
                    if (j) dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1] + prices[i-1]);
                    else dp[i][j][0] = dp[i-1][j][0];
                    
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] - prices[i-1]);
                }
            }

            return dp[days][k][0];

        } else {
            int dp[days+1][2];

            dp[0][0] = 0;
            dp[0][1] = INT_MIN; 

            for (int i = 1; i <= days; ++i) {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);      
                dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1]);
            }

            return dp[days][0];
        }

        return 0;        
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        int dp[days+1][2];

        if (days == 0) return 0;

        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        dp[1][0] = 0;
        dp[1][1] = -prices[0];

        for (int i = 2; i <= days; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i-1]);
        }

        return dp[days][0];
    }
};
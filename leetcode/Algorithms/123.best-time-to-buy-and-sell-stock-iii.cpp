//
// Created by Manh Cao on 30/01/2023.
//

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n_price = prices.size();
        vector<int> dp(n_price, 0);
        int mi = prices[0];
        for (int i = 1; i < n_price; i ++) {
            dp[i] = max(dp[i - 1], prices[i] - mi);
            mi = min(mi, prices[i]);
        }
        int ma = prices.back();
        int ans = 0;
        for (int i = n_price - 1; i >= 0; -- i) {
            ans = max(ans, dp[i] + ma - prices[i]);
            ma = max(ma, prices[i]);
        }
        return ans;
    }
};

int main() {

    Solution solution = Solution();

    int p[] = {3,3,5,0,0,3,1,4};
    vector<int> prices;

    for (int i = 0; i <= 7; i ++) prices.push_back(p[i]);

    auto ans = solution.maxProfit(prices);

    cout << ans << endl;

    return 0;
}

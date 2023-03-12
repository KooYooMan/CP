//
// Created by Manh Cao on 31/01/2023.
//

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1) return 1;
        queue<int> q;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i ++) {
            if (i == 0 && ratings[0] < ratings[1]) {
                dp[0] = 1;
                q.push(0);
            }
            else if (i == n - 1 && ratings[i] < ratings[i - 1]) {
                dp[i] = 1;
                q.push(i);
            } else if (ratings[i] < ratings[i + 1] || ratings[i] < ratings[i - 1]) {
                dp[i] = 1;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front(); q.pop();
            if (front > 0 && ratings[front] < ratings[front - 1] && dp[front - 1] < dp[front] + 1) {
                dp[front - 1] = dp[front] + 1;
                q.push(front - 1);
            }
            if (front < n - 1 && ratings[front] < ratings[front + 1] && dp[front + 1] < dp[front] + 1) {
                dp[front + 1] = dp[front] + 1;
                q.push(front + 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i ++) {
            if (dp[i] == 0) ans ++;
            else ans += dp[i];
        }
        return ans;
    }
};

int main() {

    Solution solution = Solution();

    vector<int> ratings;
    ratings.push_back(1);
    ratings.push_back(0);
    ratings.push_back(2);

    int ans = solution.candy(ratings);

    cout << ans << endl;

    return 0;
}

//
// Created by Manh Cao on 29/01/2023.
//

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        vector<int> left(n, 0);
        vector<int> candidates;
        for (int i = 0; i < n; i ++) {
            while (!candidates.empty() && heights[candidates.back()] >= heights[i]) candidates.pop_back();
            if (candidates.empty()) left[i] = 0;
            else left[i] = candidates.back() + 1;
            candidates.push_back(i);
        }

        candidates.clear();

        for (int i = n - 1; i >= 0; -- i) {
            while (!candidates.empty() && heights[candidates.back()] >= heights[i]) candidates.pop_back();
            int value;
            if (candidates.empty()) value = n - 1;
            else value = candidates.back() - 1;
            candidates.push_back(i);
            ans = max(ans, (value - left[i] + 1) * heights[i]);
        }
        return ans;
    }
};

int main() {

    int elements[] = {2, 1, 5, 6, 2, 3, 0, 2, 1, 10, 2, 3};

    vector<int> heights;

    for (int i = 0; i <= 11; i ++) {
        heights.push_back(elements[i]);
    }

    Solution solution = Solution();
    int ans = solution.largestRectangleArea(heights);

    cout << ans << endl;

    return 0;
}

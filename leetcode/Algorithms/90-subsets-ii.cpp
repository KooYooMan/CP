//
// Created by Manh Cao on 27/01/2023.
//

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<int> sorted_nums;
        for (int i = 0; i < nums.size(); i ++) sorted_nums.push_back(nums[i]);
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<int> current;
        vector<vector<int> > ans;
        trace(0, -1, sorted_nums, current, ans);
        return ans;
    }

    void trace(int pos, int lastPos, vector<int>& sorted_nums, vector<int>& current, vector<vector<int> >& ans) {
        int n_nums = sorted_nums.size();
        if (pos == n_nums) {
            ans.push_back(current);
            return;
        }

        trace(pos + 1, lastPos, sorted_nums, current, ans);
        bool can_choose = false;

        if (pos == 0) can_choose = true;
        else if (sorted_nums[pos] != sorted_nums[pos - 1]) can_choose = true;
        else if (lastPos == pos - 1) can_choose = true;

        if (can_choose) {
            current.push_back(sorted_nums[pos]);
            trace(pos + 1, pos, sorted_nums, current, ans);
            current.pop_back();
        }
    }
};

int main() {

    Solution solution = Solution();

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);

    auto ans = solution.subsetsWithDup(nums);

    for (auto l: ans) {
        for (int item: l) cout << item << " ";
        cout << endl;
    }

    return 0;
}

//
// Created by Manh Cao on 27/01/2023.
//

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target || nums[l] == target || nums[r] == target) {
                return true;
            }

            // left side
            if (nums[mid] > nums[l]) {
                if (nums[l] > target || nums[mid] < target) {
                    l = mid + 1;
                    r --;
                }
                else {
                    l ++;
                    r = mid - 1;
                }
            }
            // right side
            else if (nums[mid] < nums[r]) {
                if (nums[mid] > target || nums[r] < target) {
                    l ++;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                    r --;
                }
            }
        }
        return false;
    }
};

int main() {

    Solution solution = Solution();

    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    bool ans = solution.search(nums, 3);

    cout << ans << endl;

    return 0;
}

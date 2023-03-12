//
// Created by Manh Cao on 29/01/2023.
//

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        vector<int> pos(6001, -1);
        for (int i = 0; i < n; i ++) pos[inorder[i] + 3000] = i;
        return build(preorder, inorder, pos, 0, n - 1, 0, n - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, vector<int>& pos, int l1, int r1, int l2, int r2) {
        if (l1 > r1) {
            TreeNode* null_pointer = NULL;
            return null_pointer;
        }
        if (l1 == r1) {
            return new TreeNode(preorder[l1]);
        }
        int root = preorder[l1];
        int pos_root = pos[root + 3000];

        int num_left = pos_root - l2;

        TreeNode* left = build(preorder, inorder, pos, l1 + 1, l1 + num_left, l2, pos_root - 1);
        TreeNode* right = build(preorder, inorder, pos, l1 + num_left + 1, r1, pos_root + 1, r2);

        return new TreeNode(preorder[l1], left, right);
    }
};

void printPreOrder(TreeNode* a) {
    if (a == NULL) return;
    cout << a->val << " ";
    printPreOrder(a->left);
    printPreOrder(a->right);
}

int main() {

    Solution solution = Solution();

    int pre[] = {3, 9, 20, 15, 7};
    int in[] = {9, 3, 15, 20, 7};

    vector<int> preorder, inorder;

    for (int i = 0; i <= 4; i ++) {
        preorder.push_back(pre[i]);
        inorder.push_back(in[i]);
    }

    auto ans = solution.buildTree(preorder, inorder);

    printPreOrder(ans);

    return 0;
}

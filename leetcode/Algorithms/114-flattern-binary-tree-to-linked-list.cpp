//
// Created by Manh Cao on 30/01/2023.
//

#include<iostream>

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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        TreeNode* null_pointer = NULL;
        dfs(root, null_pointer);
    }

    void dfs(TreeNode* root, TreeNode* next) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (left == NULL && right == NULL) {
            root->right = next;
            return;
        }

        if (left != NULL) {
            root->left = NULL;
            root->right = left;
            if (right == NULL) dfs(left, next);
            else {
                dfs(left, right);
                dfs(right, next);
            }
        } else {
            dfs(right, next);
        }
    }
};

int main() {

    TreeNode* n_1 = new TreeNode(1);
    TreeNode* n_2 = new TreeNode(2);
    TreeNode* n_3 = new TreeNode(3);
    TreeNode* n_4 = new TreeNode(4);
    TreeNode* n_5 = new TreeNode(5);
    TreeNode* n_6 = new TreeNode(6);

    n_1->left = n_2; n_1->right = n_5;
    n_2->left = n_3; n_2->right = n_4;
//    n_5->right = n_6;

    Solution solution = Solution();
    solution.flatten(n_1);

    TreeNode* ans = n_1;
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->right;
    }

    return 0;
}
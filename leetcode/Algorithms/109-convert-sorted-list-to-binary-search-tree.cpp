//
// Created by Manh Cao on 29/01/2023.
//

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            TreeNode* null_pointer = NULL;
            return null_pointer;
        }

        int num = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            num ++;
            temp = temp->next;
        }

        TreeNode* root = buildDraftTree(1, num);
        dfs(root, head);
        return root;
    }

    TreeNode* buildDraftTree(int index, int limit) {
        TreeNode* ans = new TreeNode(0);
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        if (2 * index <= limit) left = buildDraftTree(2 * index, limit);
        if (2 * index + 1 <= limit) right = buildDraftTree(2 * index + 1, limit);
        ans->left = left; ans->right = right;
        return ans;
    }

    ListNode* dfs(TreeNode* root, ListNode* head) {
        if (root == NULL) return head;
        ListNode* left = dfs(root->left, head);
        root->val = left->val;
        return dfs(root->right, left->next);
    }
};

void printInorder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << endl;
    printInorder(root->left);
    printInorder(root->right);
}

int main() {

    ListNode* n_1 = new ListNode(-10);
    ListNode* n_2 = new ListNode(-3);
    ListNode* n_3 = new ListNode(0);
    ListNode* n_4 = new ListNode(5);
    ListNode* n_5 = new ListNode(9);

    n_1->next = n_2; n_2->next = n_3; n_3->next = n_4; n_4->next = n_5;

    Solution solution = Solution();

    TreeNode* ans = solution.sortedListToBST(n_1);

    printInorder(ans);

    return 0;
}
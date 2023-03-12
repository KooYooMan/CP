//
// Created by Manh Cao on 27/01/2023.
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

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode* began = head;
        int index = 1;
        while (index < left) {
            index ++;
            began = began->next;
        }

        ListNode* foo = began;
        ListNode* bar = began->next;
        while (index + 1 <= right) {
            ListNode* magic = bar->next;
            bar->next = foo;
            foo = bar;
            bar = magic;
            index ++;
        }

        began->next = bar;

        if (left == 1) {
            return foo;
        }

        ListNode* l_1 = head;
        index = 1;
        while (index < left - 1) {
            index ++;
            l_1 = l_1->next;
        }

        l_1->next = foo;
        return head;
    }
};

int main() {

    Solution solution = Solution();

    ListNode* n_4 = new ListNode();
    n_4->val = 5;

    ListNode* n_3 = new ListNode();
    n_3->val = 4; n_3->next = n_4;

    ListNode* n_2 = new ListNode();
    n_2->val = 3; n_2->next = n_3;

    ListNode* n_1 = new ListNode();
    n_1->val = 2; n_1->next = n_2;

    ListNode* n_0 = new ListNode();
    n_0->val = 1; n_0->next = n_1;

    auto ans = solution.reverseBetween(n_0, 2, 4);

    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}


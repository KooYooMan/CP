//
// Created by Manh Cao on 27/01/2023.
//
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = NULL;
        ListNode* lastValidNode = NULL;
        int lastValue = -200;

        while (head != NULL) {
            bool ok = true;
            if (head->val == lastValue) ok = false;
            if (head->next && head->next->val == head->val) ok = false;
            if (ok) {
                if (ans == NULL) ans = head;
                if (lastValidNode != NULL) lastValidNode->next = head;
                lastValidNode = head;
            }
            lastValue = head->val;
            head = head->next;
        }
        lastValidNode->next = NULL;
        return ans;
    }
};

int main() {

    Solution solution = Solution();

    ListNode* n_6 = new ListNode();
    n_6->val = 5;

    ListNode* n_5 = new ListNode();
    n_5->val = 4; n_5->next = n_6;

    ListNode* n_4 = new ListNode();
    n_4->val = 4; n_4->next = n_5;

    ListNode* n_3 = new ListNode();
    n_3->val = 3; n_3->next = n_4;

    ListNode* n_2 = new ListNode();
    n_2->val = 2;

    ListNode* n_1 = new ListNode();
    n_1->val = 2; n_1->next = n_2;

    ListNode* n_0 = new ListNode();
    n_0->val = 1; n_0->next = n_1;

    ListNode* ans = solution.deleteDuplicates(n_0);

    while(ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}
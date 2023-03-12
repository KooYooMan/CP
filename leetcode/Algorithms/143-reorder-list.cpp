//
// Created by Manh Cao on 31/01/2023.
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
    void reorderList(ListNode* head) {
        ListNode* null_pointer = NULL;
        if (head == NULL) return;

        if (head->next == NULL) return;
        if (head->next->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(true) {
            ListNode* new_slow = slow->next;
            ListNode* new_fast = fast->next->next;
            if (new_fast == NULL || new_fast->next == NULL) {
                slow->next = null_pointer;
                slow = new_slow;
                break;
            }
            slow = new_slow;
            fast = new_fast;
        }

        ListNode* middle;
        if (slow->next == NULL) middle = slow;
        else {
            ListNode* foo = slow;
            ListNode* bar = slow->next;
            foo->next = NULL;
            while(true) {
                if (bar->next == NULL) {
                    bar->next = foo;
                    middle = bar;
                    break;
                }
                ListNode* magic = bar->next;
                bar->next = foo;
                foo = bar;
                bar = magic;
            }
        }

        slow = head;
        while (true) {
            ListNode* next_slow = slow->next;
            ListNode* next_middle = middle->next;
            slow->next = middle;
            middle->next = next_slow;
            if (next_slow == NULL) {
                middle->next = next_middle;
                break;
            }
            slow = next_slow; middle = next_middle;
        }
    }
};

int main() {

    ListNode* n_1 = new ListNode(1);
    ListNode* n_2 = new ListNode(2);
    ListNode* n_3 = new ListNode(3);
    ListNode* n_4 = new ListNode(4);
    ListNode* n_5 = new ListNode(5);

    n_1->next = n_2; n_2->next = n_3; n_3->next = n_4; n_4->next = n_5;

    Solution solution = Solution();
    solution.reorderList(n_1);

    while(n_1 != NULL) {
        cout << n_1->val << " ";
        n_1 = n_1->next;
    }

    return 0;
}
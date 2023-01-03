#include<bits/stdc++.h>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
			if (head == nullptr) {
				return head;
			}

			ListNode* nextHead = head;
			for (int i = 1; i < k; i ++) {
				nextHead = nextHead->next;
				if (nextHead == nullptr) {
					break;
				}
			}
			if (nextHead == nullptr) {
				return head;
			}

			ListNode* previousNode = head;
			ListNode* nextNode = head->next;

			if (nextHead->next != nullptr) {
				head->next = reverseKGroup(nextHead->next, k);
			} else {
				head->next = nullptr;
			}
			for (int i = 1; i < k; i ++) {
				ListNode* tempNode = nextNode->next;
				nextNode->next = previousNode;
				previousNode = nextNode;
				nextNode = tempNode;
			}
			return previousNode;
    }
};

int main() {

	ListNode* e = new ListNode(5);
	ListNode* d = new ListNode(4, e);
	ListNode* c = new ListNode(3, d);
	ListNode* b = new ListNode(2, c);
	ListNode* a = new ListNode(1, b);

	Solution solution;

	ListNode* result = solution.reverseKGroup(a, 2);

	while (result != nullptr) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << "\n";

	return 0;
}

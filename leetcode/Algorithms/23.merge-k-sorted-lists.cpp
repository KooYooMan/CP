#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode* ans = nullptr;
        ListNode *lastNode = nullptr;
        set<pair<int, int>> s;

        for (int i = 0; i < (int)lists.size(); i ++) {
            ListNode* list = lists[i];
            if (list == nullptr) continue;
            s.insert(make_pair(list->val, i));
        }

        while (!s.empty()) {
            int value = (*s.begin()).first;
            int id = (*s.begin()).second;
            s.erase(s.begin());

            if (ans == nullptr) {
                ans = new ListNode(value);
                lastNode = ans;
            } else {
                lastNode->next = new ListNode(value);
                lastNode = lastNode->next;
            }

            ListNode* nextCandidate = lists[id]->next;
            if (nextCandidate == nullptr) continue;
            lists[id] = nextCandidate;
            s.insert(make_pair(nextCandidate->val, id));
        }

        return ans;
    }
};

int main()
{

    return 0;
}
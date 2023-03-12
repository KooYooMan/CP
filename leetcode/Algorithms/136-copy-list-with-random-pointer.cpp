//
// Created by Manh Cao on 31/01/2023.
//

#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            Node* null_pointer = NULL;
            return null_pointer;
        }

        vector<Node*> original;
        Node* temp = head;
        while (temp != NULL) {
            original.push_back(temp);
            temp = temp->next;
        }

        int num = original.size();
        vector<Node*> nodes;
        for (int i = 0; i < num; i ++) nodes.push_back(new Node(i));

        int index = 0;
        temp = head;
        while (temp != NULL) {
            Node* second_temp = nodes[index];
            index ++;

            second_temp->val = temp->val;
            if (index < num) second_temp->next = nodes[index];

            if (temp->random != NULL) {
                for (int i = 0; i < num; i ++) {
                    if (original[i] == temp->random) {
                        second_temp->random = nodes[i];
                        break;
                    }
                }
            }

            temp = temp->next;
        }
        return nodes[0];
    }
};

int main() {

    Solution solution = Solution();

    Node* n_1 = new Node(1);
    Node* n_2 = new Node(2);

    n_1->next = n_2; n_1->random = n_2; n_2->random = n_2;

    Node* ans = solution.copyRandomList(n_1);

    while (ans != NULL) {
        cout << ans->val;

        if (ans->next != NULL) cout << " next: " << ans->next->val;
        if (ans->random != NULL) cout << " random: " << ans->random->val;

        cout << endl;

        ans = ans->next;
    }

    return 0;
}

//
// Created by Manh Cao on 01/02/2023.
//

#include<iostream>
#include<map>

using namespace std;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int _key, int _val) {
        key = _key;
        val = _val;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:

    int cap;
    int s;
    Node* head;
    Node* tail;
    map<int, Node*> f;

    LRUCache(int capacity) {
        s = 0;
        cap = capacity;
        Node* null_pointer = NULL;
        head = null_pointer;
        f.clear();
    }

    int get(int key) {
        if (f.find(key) != f.end()) {
            Node* node = f[key];
            if (node->prev != NULL) {
                if (node->next == NULL) tail = node->prev;
                node->prev->next = node->next;
                if (node->next != NULL) node->next->prev = node->prev;

                Node* null_pointer = NULL;
                node->next = head;
                node->prev = null_pointer;
                head->prev = node;
                head = node;
            }
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (f.find(key) != f.end()) {
            Node* node = f[key];
            node->val = value;
            return;
        }

        Node* new_node = new Node(key, value);
        f[key] = new_node;
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }

        s ++;
        if (s > cap) {
            f.erase(head->key);
            head = head->next;
            Node* null_pointer = NULL;
            head->prev = null_pointer;
            s --;
        }
    }
};

int main() {

    LRUCache* obj = new LRUCache(2);
    obj->put(1,2);
    obj->put(2,2);
    int foo = obj->get(1);
    obj->put(3,3);

    return 0;
}

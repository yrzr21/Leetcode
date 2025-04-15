#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../tools.h"
using namespace std;

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
    // 深拷贝
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*, Node*> old_new;

        //  初始化
        Node* ret_head = new Node(head->val);
        old_new[head] = ret_head;
        Node* cur = head->next;
        while (cur != nullptr) {
            old_new[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur != nullptr) {
            Node* new_cur = old_new[cur];
            new_cur->random = old_new[cur->random];
            new_cur->next = old_new[cur->next];

            cur = cur->next;
        }

        return ret_head;
    }
};

// O(1) 空间解法
class Solution2 {
   public:
    // 先遍历一遍插入新节点，第二次遍历初始化 random 与 next
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* cur = head;
        while (cur != nullptr) {
            Node* new_node = new Node(cur->val);
            new_node->next = cur->next;
            cur->next = new_node;

            cur = new_node->next;
        }

        cur = head;
        while (cur != nullptr) {
            if (cur->random != nullptr) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        // 恢复原链表指针，并连接新链表
        cur = head;
        Node* ret_head = cur->next;
        while (cur != nullptr) {
            Node* next = cur->next->next;
            if (next != nullptr) cur->next->next = next->next;

            cur->next = next;
            cur = next;
        }

        print_list(head);
        print_list(ret_head);

        return head->next;
    }
};

int main(int argc, char const* argv[]) { return 0; }

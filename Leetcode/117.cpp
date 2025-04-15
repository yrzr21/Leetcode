#include <queue>
#include <iostream>
using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    // Sol1: 广搜
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty() && q.front() != nullptr) {
            int size = q.size();
            for (size_t i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                if (node == nullptr) continue;
                node->next = q.front();

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            q.push(nullptr);
        }

        return root;
    }
};

class Solution2 {
   public:
    // Sol2: 利用已建立的链表
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        root->next = nullptr;  // build first list
        Node* head = root;

        while (1) {
            cout << "head=" << head->val;
            Node* start_node = find_first_with_child(head);
            if (start_node == nullptr) break;
            cout << ", start_node=" << start_node->val;
            cout << ", next layer=";

            connect_childs(start_node);

            cout << endl;
            if (start_node->left != nullptr)
                head = start_node->left;
            else
                head = start_node->right;
        }

        return root;
    }

   private:
    Node* find_first_with_child(Node* head) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->left || cur->right) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    void connect_childs(Node* head) {
        // pre 连左，左连右，更新pre为右
        Node* pre = nullptr;
        for (Node* cur = head; cur != nullptr; cur = cur->next) {
            if (cur->left != nullptr) {
                cout << cur->left->val << " ";
                if (pre != nullptr) pre->next = cur->left;
                pre = cur->left;
            }

            if (cur->right != nullptr) {
                cout << cur->right->val << " ";
                if (pre != nullptr) pre->next = cur->right;
                pre = cur->right;
            }
        }

        if (pre != nullptr) pre->next = nullptr;  // 最后一个肯定没连上
    }
};

int main(int argc, char const* argv[]) { return 0; }

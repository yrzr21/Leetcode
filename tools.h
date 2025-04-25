#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

void convert_brackets(const string& s) {
    for (const char& c : s) {
        if (c == '[')
            cout << '{';
        else if (c == ']')
            cout << '}';
        else
            cout << c;
    }
}

template <class T>
void print_vec_vec(vector<vector<T>> vec) {
    for (auto& vect : vec) {
        for (auto& ele : vect) {
            cout << ele << " ";
        }
        cout << endl;
    }
}

ListNode* build_list(vector<int> data) {
    ListNode* head = new ListNode(data[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < data.size(); i++) {
        cur->next = new ListNode(data[i]);
        cur = cur->next;
    }

    return head;
}

template <class T>
void print_list(T* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

template <class T>
void print_vec(vector<T> vec) {
    for (auto ele : vec) {
        cout << ele << " ";
    }
    cout << endl;
}

using vec_int = std::vector<int>;
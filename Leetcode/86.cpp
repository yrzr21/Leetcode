#include "../tools.h"

class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        // 遍历整个链表，遇到一个<x的就插入到 less_cur 后面，并更新 less_cur
        // 插入时如果 less_cur 为null，则初始化head
        ListNode *less_head = nullptr, *less_cur = nullptr;
        ListNode *ge_head = nullptr, *ge_cur = nullptr;

        ListNode *cur = head, *next = head->next;
        while (cur != nullptr) {
            if (cur->val < x) {
                if (less_head == nullptr) {
                    less_head = cur;
                } else {
                    less_cur->next = cur;
                }
                less_cur = cur;
            } else {
                if (ge_head == nullptr) {
                    ge_head = cur;
                } else {
                    ge_cur->next = cur;
                }
                ge_cur = cur;
            }

            cur->next = nullptr;
            if (next == nullptr) break;
            cur = next;
            next = next->next;
        }

        if (less_cur == nullptr) {
            return ge_head;
        } else {
            less_cur->next = ge_head;
            return less_head;
        }
    }
};

int main(int argc, char const* argv[]) {
    Solution().partition(build_list({2, 1}), 2);
    return 0;
}

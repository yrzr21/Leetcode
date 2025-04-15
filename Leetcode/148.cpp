#include "../tools.h"

class Solution {
   public:
    ListNode* sortList(ListNode* head) { return sort_list(head, nullptr); }

   private:
    // 递归
    // 给定一个链表的一部分 [head, tail)，将其割裂下来，返回已排序链表
    ListNode* sort_list(ListNode* head, ListNode* tail) {
        if (head == nullptr) return nullptr;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }

        // find mid
        ListNode *f = head, *s = head;
        while (f != tail) {
            f = f->next;
            if (f == tail) break;
            s = s->next;
            f = f->next;
        }
        ListNode* mid = s;

        // 排序两边
        ListNode* left = sort_list(head, mid);
        ListNode* right = sort_list(mid, tail);

        // 合并
        ListNode* cur_l = left;
        ListNode* cur_r = right;

        if (left->val > right->val) {
            cur_r = cur_r->next;
            head = right;
        } else {
            cur_l = cur_l->next;
            head = left;
        }

        ListNode* cur = head;
        while (cur_l != nullptr || cur_r != nullptr) {
            if (cur_l == nullptr || (cur_r!=nullptr && cur_r->val < cur_l->val)) {
                cur->next = cur_r;
                cur_r = cur_r->next;
            } else {
                // cur_l!=nulptr && cur_l->val <= ~
                cur->next = cur_l;
                cur_l = cur_l->next;
            }

            cur = cur->next;
        }
        cur->next = nullptr;
        print_list(head);

        return head;
    }
};

int main(int argc, char const* argv[]) {
    Solution().sortList(build_list({4, 2, 1, 3}));
    return 0;
}

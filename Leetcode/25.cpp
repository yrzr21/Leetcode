#include "../tools.h"

class Solution {
   private:
    // 反转 [head, last]
    void reverse(ListNode* head_pre, ListNode* head, ListNode* last) {
        ListNode *pre = head, *cur = head->next, *next = cur->next;

        if (head_pre != nullptr) head_pre->next = last;
        head->next = last->next;

        while (pre != last) {
            cur->next = pre;
            if (next == nullptr) return;
            pre = cur;
            cur = next;
            next = next->next;
        }
    }

   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;

        // 第一轮
        ListNode *cur = head, *first_pre = nullptr, *first = cur, *last;
        for (size_t i = 1; i < k; i++) {
            if (cur == nullptr) return head;
            cur = cur->next;
        }
        if (cur == nullptr) return head;
        last = cur;
        head = cur;
        cur = cur->next;
        reverse(first_pre, first, last);

        first_pre = first;
        while (cur != nullptr) {
            first = cur;
            for (size_t i = 1; i < k; i++) {
                if (cur == nullptr) return head;
                cur = cur->next;
            }
            if (cur == nullptr) return head;
            last = cur;
            cur = cur->next;
            reverse(first_pre, first, last);
            first_pre = first;
        }

        return head;
    }
};

int main(int argc, char const* argv[]) {
    print_list(Solution().reverseKGroup(build_list({1, 2, 3, 4, 5}), 2));
    return 0;
}

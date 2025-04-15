#include "../tools.h"

class Solution {
   public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *pre = nullptr, *cur = head, *fast = head;

        if (n != 1) {
            while (n-- > 0) fast = fast->next;
        } else {
            while (cur->next != nullptr) {
                pre = cur;
                cur = cur->next;
            }
            if (pre == nullptr) return nullptr;
            pre->next = nullptr;
            return head;
        }

        while (fast != nullptr) {
            pre = cur;
            cur = cur->next;
            fast = fast->next;
        }
        if (pre == nullptr) {
            // 删除第一个
            head = head->next;
        } else {
            pre->next = cur->next;
        }

        return head;
    }
};

int main(int argc, char const *argv[]) {
    Solution().removeNthFromEnd(build_list({1, 2}), 2);
    return 0;
}

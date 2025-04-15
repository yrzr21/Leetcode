#include "../tools.h"

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *cur = head, *pre = nullptr;
        while (cur != nullptr) {
            ListNode* first = cur;
            cur = cur->next;
            while (cur != nullptr && cur->val == first->val) cur = cur->next;
            // cur 为 nullptr 或不同的val第一个元素
            if (cur != first->next) {
                if (pre == nullptr) {
                    head = cur;
                } else {
                    pre->next = cur;
                }
            } else {
                pre = first;
            }
        }
        return head;
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}

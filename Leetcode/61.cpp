#include "../tools.h"

class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;
        // 计算长度
        int len = 0;
        ListNode* pre = nullptr;
        for (ListNode* cur = head; cur != nullptr; pre = cur, cur = cur->next) {
            len++;
        }
        k = k % len;
        if (k == 0) return head;
        // 移动后k个到前面，即last->next=第k个;倒数第k-1个->next=nullptr;head=第k个
        ListNode* last = pre;

        int n = len - k - 1;
        ListNode* cur = head;
        while (n-- > 0) {
            cur = cur->next;
        }
        last->next = head;
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};

int main(int argc, char const* argv[]) { return 0; }

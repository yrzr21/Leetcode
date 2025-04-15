#include "../tools.h"

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        cout << "list=";
        print_list(head);

        if (left == right) return head;
        ListNode *cur = head, *left_node, *right_node, *left_pre, *right_after;
        right -= left;

        // 移动到 left 之前的一个节点，标记
        if (left == 1) {
            left_pre = nullptr;
            left_node = head;
        } else {
            while (left > 2) {
                cur = cur->next;
                left--;
            }
            left_pre = cur;
            cur = cur->next;
            left_node = cur;
        }

        // 移动到 right
        // 此处 right 必 >= 2
        while (right > 0) {
            cur = cur->next;
            right--;
        }
        right_node = cur;
        cout << "*left=" << left_node->val << ", *right=" << right_node->val
             << endl;

        // 开始反转
        if (left_pre != nullptr) {
            left_pre->next = right_node;
        } else {
            head = right_node;
        }
        cur = left_node->next;
        ListNode *pre = left_node, *next = cur->next;
        // 右边
        left_node->next = right_node->next;
        // 反转 [left,right] 内部
        while (pre != right_node) {
            cur->next = pre;
            if (next == nullptr) break;

            pre = cur;
            cur = next;
            next = next->next;
        }

        return head;
    }
};

int main(int argc, char const* argv[]) {
    ListNode* list_head = build_list({3, 5});
    Solution().reverseBetween(list_head, 1, 2);
    return 0;
}

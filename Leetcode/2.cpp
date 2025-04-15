#include "../tools.h"

// 我勒个石山代码击败100%啊
class Solution {
   public:
    // 加到 l1 中
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        print_list(l1);
        print_list(l2);

        int c = 0;  // 进位
        ListNode *head = l1;
        ListNode *l1_pre = nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            int result = l1->val + l2->val + c;
            cout << l1->val << "+" << l2->val << "+" << c << "=" << result
                 << endl;

            if (result >= 10) {
                l1->val = result % 10;
                c = 1;
            } else {
                l1->val = result;
                c = 0;
            }

            l1_pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == nullptr && l2 != nullptr) {
            // l1 仅有一位数
            l1 = l2;
            if (l1_pre == nullptr) {
                head->next = l2;
            } else {
                l1_pre->next = l2;
            }

            while (l1 != nullptr) {
                int result = c + l1->val;
                cout << l1->val << "+" << c << "=" << result << endl;
                if (result >= 10) {
                    l1->val = result % 10;
                    c = 1;
                } else {
                    l1->val = result;
                    c = 0;
                    break;
                }

                l1_pre = l1;
                l1 = l1->next;
            }
        } else if (l1 != nullptr && l2 == nullptr) {
            while (l1 != nullptr) {
                int result = c + l1->val;
                cout << l1->val << "+" << c << "=" << result << endl;
                if (result >= 10) {
                    l1->val = result % 10;
                    c = 1;
                } else {
                    l1->val = result;
                    c = 0;
                    break;
                }

                l1_pre = l1;
                l1 = l1->next;
            }
        }

        if (c != 0) l1_pre->next = new ListNode(c);
        cout << "result=";
        print_list(head);
        return head;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> l1{9, 9, 9, 9, 9, 9, 9}, l2{9, 9, 9, 9};
    Solution().addTwoNumbers(build_list(l1), build_list(l2));

    return 0;
}

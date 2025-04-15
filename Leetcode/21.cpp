#include "../tools.h"

class Solution {
   public:
    // 2个遍历指针，1个新链表指针，哪个小把哪个插进去，一样大先插入 l1
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;

        // 初始化
        ListNode *l1, *l2, *cur, *ret_head;
        if (list1->val < list2->val) {
            cout << l1->val << "<" << l2->val << endl;
            ret_head = list1;
            l1 = list1->next;
            l2 = list2;
        } else {
            cout << list1->val << ">=" << list2->val << endl;
            ret_head = list2;
            l1 = list1;
            l2 = list2->next;
        }
        cur = ret_head;

        // 遍历
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cout << l1->val << "<" << l2->val << endl;
                cur->next = l1;
                l1 = l1->next;
            } else {
                cout << l1->val << ">=" << l2->val << endl;
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if (l1 == nullptr)
            cur->next = l2;
        else
            cur->next = l1;
        print_list(ret_head);
        return ret_head;
    }
};

int main(int argc, char const* argv[]) {
    vector<int> l1{1, 2, 4}, l2{1, 3, 4};
    Solution().mergeTwoLists(build_list(l1), build_list(l2));
    return 0;
}

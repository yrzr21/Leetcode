#include "../tools.h"

class Solution {
   public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        ListNode *fast = head, *slow = head;
        while (true) {
            fast = fast->next;
            slow = slow->next;
            if (fast == nullptr) return false;
            fast = fast->next;
            if (fast == nullptr) return false;
            if (fast == slow) return true;
        }
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}

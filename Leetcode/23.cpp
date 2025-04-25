#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        return mergeKLists(lists, 0, lists.size());
    }

   private:
    // [l,r)
    ListNode *mergeKLists(vector<ListNode *> &lists, int l, int r) {
        if (l >= r) return nullptr;
        if (l + 1 == r) return lists[l];
        
        int mid = (l + r) / 2;

        ListNode *l_head = mergeKLists(lists, l, mid);
        ListNode *r_head = mergeKLists(lists, mid, r);

        ListNode *l_iter = l_head;
        ListNode *r_iter = r_head;

        ListNode dummy;
        ListNode *cur = &dummy;
        while (l_iter != nullptr || r_iter != nullptr) {
            if (l_iter == nullptr ||
                (r_iter != nullptr && r_iter->val < l_iter->val)) {
                cur->next = r_iter;
                r_iter = r_iter->next;
            } else {
                // l!=nullptr
                cur->next = l_iter;
                l_iter = l_iter->next;
            }

            cur = cur->next;
        }
        cur->next = nullptr;

        return dummy.next;
    }
};

int main(int argc, char const *argv[]) { return 0; }

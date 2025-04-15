#include "../tools.h"

class LRUCache {
   private:
    struct node {
        node(int key, int val, struct node* next, struct node* pre)
            : key(key), val(val), next(next), pre(pre) {}
        int val;
        int key;
        struct node* next;
        struct node* pre;
    };

    int capacity;
    int size = 0;
    struct node head{-1, -1, &head, &head};
    unordered_map<int, struct node*> map;

   private:
    void move_ahead(struct node* node) {
        remove_from_list(node);
        insert_after(&head, node);
    }
    void insert_after(struct node* node, struct node* new_node) {
        new_node->next = node->next;
        new_node->pre = node;

        node->next->pre = new_node;
        node->next = new_node;
    }
    void remove_from_list(struct node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void delete_last() {
        if (head.pre == &head) return;

        struct node* toDel = head.pre;

        map.erase(head.pre->key);
        head.pre->pre->next = &head;
        head.pre = head.pre->pre;

        delete toDel;
    }

   public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto iter = map.find(key);
        if (iter == map.end()) return -1;
        move_ahead(iter->second);
        return iter->second->val;
    }

    void put(int key, int value) {
        if (map.contains(key)) {
            map[key]->val = value;
            move_ahead(map[key]);
            return;
        }

        if (size == capacity) {
            delete_last();
        } else {
            size++;
        }
        struct node* node = new struct node(key, value, head.next, &head);
        insert_after(&head, node);
        map[key] = node;
    }
};

int main(int argc, char const* argv[]) {
    LRUCache(1);
    return 0;
}

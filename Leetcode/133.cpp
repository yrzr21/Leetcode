#include "../tools.h"

class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
// 两种思路：1.哈希表 2.把节点插入到原图中

// 哈希表
class Solution {
   public:
    // 遍历图，每个节点对应一个 new 出来的节点，第二次遍历时连接
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        queue<Node*> q;
        q.push(node);
        map.insert({node, new Node(node->val)});

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            for (Node* node_ : cur->neighbors) {
                if (map.find(node_) != map.end()) continue;
                q.push(node_);

                Node* new_node = new Node(node_->val);
                map.insert({node_, new_node});
            }
        }

        // 第二次遍历

        for (auto [old_node, new_node] : map) {
            cout << new_node->val << ": ";
            for (Node* old_neighbour : old_node->neighbors) {
                cout << old_neighbour->val << " ";
                new_node->neighbors.push_back(map[old_neighbour]);
            }
            cout << endl;
        }

        return map.begin()->second;
    }

   private:
    unordered_map<Node*, Node*> map;  // 原图，新图
};

// Sol2：引入中间节点--好麻烦似乎
class Solution2 {
public:
    // 在每一个节点及其邻居间引入中间节点，中间节点的邻居只有源节点及其下一个节点
    // 中间节点的邻居0为源节点，1为去向节点
    // 引入中间节点环绕当前节点（同一个中间节点），
    // 我靠编不下去了，算了，有缘再写
    Node* cloneGraph(Node* node) {
        
    }
};
int main(int argc, char const* argv[]) {
    return 0;
}

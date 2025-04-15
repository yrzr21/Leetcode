#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    Node() : parent(this), times(1.0) {}
    Node* parent;  // nullptr表示为基准节点，其倍数为1
    double times;  // parent/node=times
};

class Solution {
   public:
    // queries 中若有相同字母则可消去，可以通过组合 equations
    // 的方式得到queries，无法组合的为-1（包括无法组合和出现未知字母的情况）
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            Node *node1, *node2;
            if (map.find(equations[i][0]) == map.end()) {
                node1 = new Node();
                map[move(equations[i][0])] = node1;
            } else {
                node1 = map[move(equations[i][0])];
            }
            if (map.find(equations[i][1]) == map.end()) {
                node2 = new Node();
                map[move(equations[i][1])] = node2;
            } else {
                node2 = map[move(equations[i][1])];
            }

            union_nodes(node1, node2, values[i]);
        }

        // query
        vector<double> ans;
        for (size_t i = 0; i < queries.size(); i++) {
            if (map.find(queries[i][0]) == map.end() ||
                map.find(queries[i][1]) == map.end() ||
                !has_answer(map[queries[i][0]], map[queries[i][1]])) {
                ans.push_back(-1);
            } else {
                // parent 相同
                // parent/node1=node1->times
                // parent/node2=node2->times
                ans.push_back(map[queries[i][1]]->times /
                              map[queries[i][0]]->times);
            }
        }
        return ans;
    }

   private:
    unordered_map<string, Node*> map;  // name node

    // node1/node2=times
    void union_nodes(Node* node1, Node* node2, double times) {
        // if (node1 == nullptr || node2 == nullptr) return;

        Node *base1 = find_base(node1), *base2 = find_base(node2);
        if (base1 == base2) return;
        // node1/node2=times
        // node->parent=base
        // 求base1/base2=node1->parent/node2->parent=node1->times*node1/(node2->times*node2)=~
        base2->parent = base1;
        base2->times = times * node1->times / node2->times;
    }

    Node* find_base(Node* node) {
        // if (node == nullptr) return nullptr;
        if (node->parent == node) return node;

        // else
        Node* base = find_base(node->parent);
        // base/parent = times1; parent/node=times2
        node->times *= node->parent->times;
        node->parent = base;
        return base;
    }

    // 等价于是否相连
    bool has_answer(Node* node1, Node* node2) {
        return find_base(node1) == find_base(node2);
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<string>> equations = {{"a", "e"}, {"b", "e"}};
    vector<double> values{4.0, 3.0};
    vector<vector<string>> queries{{"a", "b"}, {"e", "e"}, {"x", "x"}};

    Solution().calcEquation(equations, values, queries);

    return 0;
}

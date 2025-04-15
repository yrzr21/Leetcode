#include "../tools.h"

class Solution {
   public:
    // start->end，改变每一位为ACGT查看是否在bank中，统计距离
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) return 0;
        this->endGene = move(endGene);
        for (size_t i = 0; i < bank.size(); i++) {
            visited.insert({move(bank[i]), false});
        }
        visited.insert({startGene, false});
        if (!visited.contains(this->endGene)) return -1;

        backtrack(startGene, 0);
        return ans == INT32_MAX ? -1 : ans;
    }

   private:
    unordered_map<string, bool> visited;
    const vector<char> keys{'A', 'C', 'G', 'T'};
    int ans = INT32_MAX;
    string endGene;

    void backtrack(string& gene, int step) {
        if (!visited.contains(gene)) return;
        if (visited[gene]) return;

        cout << "gene=" << gene << ", step=" << step << endl;
        visited[gene] = true;
        if (gene == endGene) {
            ans = min(step, ans);
            return;
        }

        for (size_t i = 0; i < 8; i++) {
            char origin = gene[i];
            for (size_t j = 0; j < keys.size(); j++) {
                char key = keys[j];
                if (key == origin) continue;
                gene[i] = key;
                backtrack(gene, step + 1);
            }
            gene[i] = origin;
        }
    }
};

int main(int argc, char const* argv[]) {
    vector<string> v{"AAAACCCA", "AAACCCCA", "AACCCCCA", "AACCCCCC",
                     "ACCCCCCC", "CCCCCCCC", "AAACCCCC", "AACCCCCC"};
    Solution().minMutation("AAAACCCC", "CCCCCCCC", v);
    return 0;
}

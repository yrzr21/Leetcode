#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string intToRoman(int num) {
        vector<pair<string, int>> rule{
            {"I", 1},   {"IV", 4},   {"V", 5},    {"IX", 9},  {"X", 10},
            {"XL", 40}, {"L", 50},   {"XC", 90},  {"C", 100}, {"CD", 400},
            {"D", 500}, {"CM", 900}, {"M", 1000},
        };

        int i = rule.size() - 1;
        string ret;
        while (num > 0) {
            if (num >= rule[i].second) {
                num -= rule[i].second;
                ret += rule[i].first;
            } else {
                while (i >= 0 && num < rule[i].second) i--;
                if (i < 0) break; // num=0
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) { return 0; }

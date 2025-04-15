#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int size = s.size();
        int nmid = numRows - 2;
        int nz = 2 * numRows + nmid;  // 一个完整Z的长度
        // 一个Z装不下必定产生下一个z，一个Z长度为numRows+nmid
        // x个完整的Z长度为 x*nz-(x-1)*numRows=x*(numRows + nmid)+numRows

        // z数
        int z = (size - numRows) / (numRows + nmid) +
                (((size - numRows) % (numRows + nmid)) != 0);
        // 列数
        int ncol = z + 1 + nmid * z;
        int gap = 2 * (nmid + 1);

        string ret;
        for (size_t row = 1; row <= numRows; row++) {
            // 处理一行
            int start = row - 1;  // 该行的第一个元素
            // 有z个中间元素
            for (size_t i = 0; i < z && start < size; i++, start += gap) {
                ret.push_back(s[start]);
                if (row != 1 && row != numRows &&
                    start + 2 * numRows - 2 * row < size)  // 非首尾行
                    ret.push_back(s[start + 2 * numRows - 2 * row]);
            }
            // 处理最后一个列元素
            if (start < size) ret.push_back(s[start]);
        }
        return ret;

        // 元素可被分为中间元素，以及列元素，首尾行元素只有列元素
        // 任意相同位置元素间隔=nmid*2+1，即若当前元素Index为i，则下一个为i+(nmid*2+1)+1
        // 相同位置定义：同行列元素，同行中间1元素...，同行中间nmid元素
        // 赋值顺序为：列--中间1--中间2..--中间nmid--列...

        // 同行只可能有一种中间x元素
        // 除首行外，第一行的x=nmid，对于第i行，i+x=nmid+1，若包含首尾行则i+x=nmid+2，即x=numRows-row
        // 计算得出的 x>nmid或=0则无效，无中间元素，即首尾行

        // row属于[1,size]
        // 第row行第一个元素位于 row-1，其相邻中间元素位于
        // start+1+2*(numRows-1-row)=start+2*numRows-1-2*row
    }
};

int main(int argc, char const* argv[]) { return 0; }

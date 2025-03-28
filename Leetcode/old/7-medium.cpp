#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long long res = 0, target = x;
        if (x < 0)
            target = -target;
        while (target)
        {
            res = res * 10 + target % 10;
            target /= 10;
            if (x < 0 && -res < INT32_MIN)
            {
                res = 0;
                break;
            }
            else if (x >= 0 && res > INT32_MAX)
            {
                res = 0;
                break;
            }
        }
        if (x < 0)
            res = -res;
        return res;
    }
};
// @lc code=end

int main()
{
    int x;
    cin >> x;
    Solution solution;
    cout << solution.reverse(x) << "\n";
}

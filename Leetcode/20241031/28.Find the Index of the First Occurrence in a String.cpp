/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=20001
 *
 * [28] 找出字符串中第一个匹配项的下标
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        string s = needle + "#" + haystack;
        vector<int> pi(s.length());
        for (int i = 1; i < s.length(); i++)
        {
            int len = pi[i - 1];
            while (len && s[i] != s[len])
                len = pi[len - 1];
            if (s[i] == s[len])
            {
                pi[i] = len + 1;
                if (pi[i] == needle.length())
                    return i - 2 * needle.length();
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */


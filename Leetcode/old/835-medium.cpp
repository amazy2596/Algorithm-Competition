#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=835 lang=cpp
 *
 * [835] 图像重叠
 */

// @lc code=start
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for (int dx = -n; dx <= n; dx++)
        {
            for (int dy = -n; dy <= n; dy++)
            {
                int temp = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        int new_x = i + dx, new_y = j + dy;
                        if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n)
                            continue;
                        if (img1[new_x][new_y] == 1 && img2[i][j] == 1)
                            temp++;
                    }
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};
// @lc code=end



int main()
{
    Solution solution;

}
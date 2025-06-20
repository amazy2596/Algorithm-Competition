#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool f = 1;
        if (n == 1 || m == 1)
            return f;
        for (int i = 0; i < max(n, m) && f; i++)
        {
            if (i < n)
            {
                int target = matrix[i][0];
                for (int j = 0; j < m && i + j < n && f; j++)
                {
                    if (matrix[i + j][j] != target)
                        f = 0;
                }
            }
            if (i < m)
            {
                int target = matrix[0][i];
                for (int j = 0; j < n && i + j < m && f; j++)
                {
                    if (matrix[j][i + j] != target)
                        f = 0;
                }
            }
        }
        return f;
    }
};
// @lc code=end



int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    Solution solution;
    solution.isToeplitzMatrix(a);
}
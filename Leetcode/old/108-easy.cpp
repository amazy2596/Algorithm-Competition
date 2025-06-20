#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        auto calc = [&](auto calc, int l, int r) -> TreeNode*
        {
            if (l > r)
                return NULL;
            int mid = (l + r) / 2;

            TreeNode *root = new TreeNode(nums[mid]);
            root->left = calc(calc, l, mid - 1);
            root->right = calc(calc, mid + 1, r);

            return root;
        };

        return calc(calc, 0, nums.size() - 1);
    }
};
// @lc code=end



int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Solution solution;
    solution.sortedArrayToBST(a);
}
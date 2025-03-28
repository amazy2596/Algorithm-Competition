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
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
class Solution {
public:
    bool f = true;

    void dfs(TreeNode *p, TreeNode *q)
    {
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
        {
            f = false;
            return;
        }
        if (!f || (p == NULL && q == NULL))
            return;
        dfs(p->left, q->left);
        if (p->val != q->val)
            f = false;
        dfs(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p, q);
        return f;
    }
};
// @lc code=end



int main()
{
    Solution solution;

}
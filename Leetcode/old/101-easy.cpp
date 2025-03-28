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
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
        dfs(p->left, q->right);
        if (p->val != q->val)
            f = false;
        dfs(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        dfs(root->left, root->right);
        return f;
    }
};
// @lc code=end



int main()
{
    Solution solution;

}
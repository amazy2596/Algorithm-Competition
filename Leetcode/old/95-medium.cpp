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
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> res;
    vector<TreeNode*> calc(int l, int r)
    {
        vector<TreeNode*> trees;
        if (l > r)
        {
            trees.push_back(NULL);
            return trees;
        }

        for (int mid = l; mid <= r; mid++)
        {
            vector<TreeNode*> left = calc(l, mid - 1);
            vector<TreeNode*> right = calc(mid + 1, r);

            for (auto leftTree : left)
            {
                for (auto rightTree : right)
                {
                    auto *root = new TreeNode(mid);

                    root->left = leftTree;
                    root->right = rightTree;

                    trees.push_back(root);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        return calc(1, n);
    }
};
// @lc code=end



int main()
{
    Solution solution;

}
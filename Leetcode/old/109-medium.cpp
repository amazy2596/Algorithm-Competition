#include<bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int n = 0;
    ListNode* get_node(int pos, ListNode *head)
    {
        for (int i = 0; i < pos; i++)
            head = head->next;
        return head;
    }

    TreeNode* build(int l, int r, ListNode *head)
    {
        if (l > r)
            return NULL;
        int mid = (l + r) / 2;

        TreeNode *root = new TreeNode(get_node(mid, head)->val);

        root->left = build(l, mid - 1, head);
        root->right = build(mid + 1, r, head);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *cur = head;
        while (cur != NULL)
            cur = cur->next, n++;
        return build(0, n - 1, head);
    }
};
// @lc code=end



int main()
{
    Solution solution;

}
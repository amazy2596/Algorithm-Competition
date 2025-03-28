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

/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *small = new ListNode, *large = new ListNode;

        ListNode *record_small = small, *record_large = large;

        for (ListNode *q = head; q != NULL; q = q->next)
        {
            if (q->val < x)
            {
                small->next = new ListNode(q->val);
                small = small->next;
            }
            else 
            {
                large->next = new ListNode(q->val);
                large = large->next;
            }
        }
        small->next = record_large->next;
        
        return record_small->next;
    }
};
// @lc code=end



int main()
{
    int n, x;
    cin >> n >> x;
    vector<ListNode*> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = new ListNode;
        int x;
        cin >> x;
        a[i]->val = x;
        if (i)
            a[i - 1]->next = a[i];
    }
    Solution solution;
    solution.partition(a[0], x);
}
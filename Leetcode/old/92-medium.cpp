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
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL || left == right)
            return head;
        ListNode *beg = new ListNode(0, head), *ed = head;
        head = beg;
        for (int i = 1; i < left; i++)
            beg = beg->next;
        for (int i = 1; i <= right; i++)
            ed = ed->next;
        ListNode *pre = NULL, *cur = NULL, *nex = NULL;
        if (beg->next != NULL)
            pre = beg->next;
        if (pre->next != NULL) 
            cur = pre->next;
        if (cur->next != NULL)
            nex = cur->next;
        int pos = 1;
        while (cur != ed)
        {
            if (pre == beg->next)
                pre->next = ed;
            cur->next = pre;

            pre = cur;
            cur = nex;
            if (nex != NULL)
                nex = nex->next;
        }

        beg->next = pre;

        return head->next;
    }
};
// @lc code=end



int main()
{
    int n;
    cin >> n;
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
    solution.reverseBetween(a[0], 1, 2);
}
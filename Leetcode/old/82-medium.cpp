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
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode *res = new ListNode;
        res->next = head;
        ListNode *pre = res, *cur = head, *nex = head->next;
        while (nex != NULL)
        {
            bool f = true;
            while (nex != NULL && cur->val != nex->val)
            {
                f = false;
                pre = cur;
                cur = nex;
                nex = nex->next;
            }
            
            while (nex != NULL && cur->val == nex->val)
                nex = nex->next;
            if (f)
            {
                pre->next = nex;
                cur = pre->next;
            }
            if (cur != NULL)
                nex = cur->next;
            else 
                nex = NULL;
        }
        return res->next;
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
    solution.deleteDuplicates(a[0]);
}
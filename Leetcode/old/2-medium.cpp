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
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode;
        ListNode *pre = res;
        int cnt = 0;
        while (l1 != nullptr && l2 != nullptr)
        {
            int num = l1->val + l2->val + cnt;
            cnt = num / 10;
            num %= 10;
            ListNode *cur = new ListNode;
            cur->val = num;
            pre->next = cur;
            pre = cur;
            l1 = l1->next, l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            int num = l1->val + cnt;
            cnt = num / 10;
            num %= 10;
            ListNode *cur = new ListNode;
            cur->val = num;
            pre->next = cur;
            pre = cur;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            int num = l2->val + cnt;
            cnt = num / 10;
            num %= 10;
            ListNode *cur = new ListNode;
            cur->val = num;
            pre->next = cur;
            pre = cur;
            l2 = l2->next;
        }
        if (cnt != 0)
        {
            ListNode *cur = new ListNode;
            cur->val = cnt;
            pre->next = cur;
        }
        return res->next;
    }
};
// @lc code=end



int main()
{
    int n, m;
    cin >> n >> m;
    vector<ListNode*> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        a[i] = new ListNode;
        int x;
        cin >> x;
        a[i]->val = x;
        if (i)
            a[i - 1]->next = a[i];
    }
    for (int i = 0; i < m; i++)
    {
        b[i] = new ListNode;
        int x;
        cin >> x;
        b[i]->val = x;
        if (i)
            b[i - 1]->next = b[i];
    }
    Solution solution;
    cout << solution.addTwoNumbers(a[0], b[0]) << "\n";
}
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
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
        stack<ListNode*> s1, s2;
        while (l1 != nullptr)
            s1.push(l1), l1 = l1->next;
        while (l2 != nullptr)
            s2.push(l2), l2 = l2->next;

        ListNode *res = new ListNode;
        ListNode *cur = res;
        int t = 0;
        while (!s1.empty() && !s2.empty())
        {
            auto top1 = s1.top(), top2 = s2.top();
            s1.pop(), s2.pop();
            int sum = top1->val + top2->val;
            sum += t;
            t = sum / 10;
            sum %= 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
        }
        while (!s1.empty())
        {
            auto top = s1.top();
            s1.pop();
            int val = top->val + t;
            t = val / 10;
            val %= 10;
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        while (!s2.empty())
        {
            auto top = s2.top();
            s2.pop();
            int val = top->val + t;
            t = val / 10;
            val %= 10;
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        if (t != 0)
            cur->next = new ListNode(t);
        stack<ListNode*> ans;
        for (ListNode *cur = res->next; cur != nullptr; cur = cur->next)
            ans.push(cur);
        cur = res;
        res->next = nullptr;
        while (!ans.empty())
        {
            cur->next = ans.top();
            cur = cur->next;
            ans.pop();
        }
        cur->next = nullptr;
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
    solution.addTwoNumbers(a[0], b[0]);
}
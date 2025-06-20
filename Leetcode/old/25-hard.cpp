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
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        head = calc(head, k);
        return head;
    }

    ListNode* calc(ListNode *head, int k)
    {
        ListNode *tail = head;
        for (int i = 0; i < k; i++)
        {
            if (tail == NULL)
                return head;
            tail = tail->next;
        }
        ListNode *next_head = calc(tail, k);

        ListNode *pre = head, *cur = NULL, *nex = NULL;
        if (pre->next != NULL)
        {
            cur = pre->next;
            if (cur->next != NULL)
            {
                nex = cur->next;
            }
        }
        while (cur != tail && pre != NULL && cur != NULL)
        {
            if (pre == head)
                pre->next = next_head;
            cur->next = pre;

            pre = cur;
            cur = nex;
            if (nex != NULL)
                nex = nex->next;
        }

        head->next = next_head;
        
        return pre;
    }
};
// @lc code=end

int main()
{
    int n, k;
    cin >> n >> k;
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
    solution.reverseKGroup(a[0], k);
}
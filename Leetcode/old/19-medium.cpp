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
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = head;
        for (int i = 1; i < n; i++)
            p1 = p1->next;
        int i = 0;
        for ( ; p1->next != NULL; i++)
        {
            p1 = p1->next;
            if (i)
                p2 = p2->next;
        }
        if (i == 0)
            return head->next;
        if (p2->next != NULL)
        {
            ListNode *remove = p2->next;
            if (remove->next != NULL)
                p2->next = remove->next;
            else 
                p2->next = NULL;
        }
        else 
            head = NULL;
        return head;
    };
};
// @lc code=end



int main()
{
    int n;
    cin >> n;
    int pos;
    cin >> pos;
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
    cout << solution.removeNthFromEnd(a[0], pos) << "\n";
}
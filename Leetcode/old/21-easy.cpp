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
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode;
        ListNode *cur = head;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
                cur->next = list1, list1 = list1->next;
            else 
                cur->next = list2, list2 = list2->next;
            cur = cur->next;
        }
        while (list1 != NULL)
            cur->next = list1, cur = cur->next, list1 = list1->next;
        while (list2 != NULL)
            cur->next = list2, cur = cur->next, list2 = list2->next;
        if (head->next != NULL)
            return head->next;
        else 
            return NULL;
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
    cout << solution.mergeTwoLists(a[0], b[0]) << "\n";
}
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
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *res = new ListNode(-1);
        res->next = head;
        ListNode *node1 = NULL, *node2 = NULL, *node3 = NULL, *node4 = NULL;
        node1 = res;
        if (node1->next != NULL)
        {
            node2 = node1->next;
            if (node2->next != NULL)
            {
                node3 = node2->next;
                if (node3->next != NULL)
                {
                    node4 = node3->next;
                }
            }
        }
        while (node3 != NULL && node4 != NULL)
        {
            node2->next = node4;
            node3->next = node2;
            node1->next = node3;

            node1 = node2;
            node2 = node4;
            node3 = node4->next;
            if (node4->next != NULL)
                node4 = node4->next->next;
        }
        if (node3 != NULL)
        {
            node2->next = NULL;
            node3->next = node2;
            node1->next = node3;
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
    ListNode *res;
    if (n == 0)
        res = solution.swapPairs(new ListNode);
    else 
        res = solution.swapPairs(a[0]);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
}
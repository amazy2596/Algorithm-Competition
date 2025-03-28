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
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0)
            return head;
        int size = 0;
        for (ListNode *temp = head; temp != NULL; temp = temp->next)
            size++;
        k %= size;
        ListNode *pre = head, *nex = head;
        for (int i = 0; i < k; i++)
        {
            if (nex->next == NULL)
                nex = head;
            else
                nex = nex->next;
        }
        while (nex->next != NULL)
        {
            if (pre->next == NULL)
                pre = head;
            else
                pre = pre->next;
            if (nex->next == NULL)
                nex = head;
            else
                nex = nex->next;
        }
        ListNode *res = head;
        if (pre->next != NULL)
        {
            res= pre->next;
            nex->next = head;
        }
        pre->next = NULL;
        return res;
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
    solution.rotateRight(a[0], k);
}
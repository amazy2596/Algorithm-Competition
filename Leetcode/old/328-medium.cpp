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
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *res = head;
        ListNode *odds = new ListNode, *evens = new ListNode;
        ListNode *odd = odds, *even = evens;
        int i = 0;
        for (ListNode *cur = head; cur != nullptr; cur = cur->next)
        {
            i++;
            if (i % 2 == 1)
            {
                odd->next = cur;
                odd = odd->next;
            }
            else
            {
                even->next = cur;
                even = even->next;
            }
        }
        even->next = nullptr;
        odd->next = evens->next;
        return res;
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
    solution.oddEvenList(a[0]);
}
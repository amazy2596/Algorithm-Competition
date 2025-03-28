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
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
        ListNode *cur = head, *nex = cur->next;
        while (nex != NULL)
        {
            while (nex != NULL && cur->val != nex->val)
            {
                cur = nex;
                nex = nex->next;
            }

            while (nex != NULL && cur->val == nex->val)
                nex = nex->next;
            
            cur->next = nex;

            cur = nex;
            if (nex != NULL)
                nex = nex->next;
        }

        return res->next;
    }
};
// @lc code=end



int main()
{
    Solution solution;

}
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
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        for (ListNode *cur = head; cur != nullptr; cur = cur->next)
            n++;
        int pre = n % k, num = n / k;
        vector<ListNode*> res;
        while (pre--)
        {
            int cnt = 0;
            ListNode *cur = head;
            while (cnt < num)
            {
                cnt++;
                cur = cur->next;
            }
            res.push_back(head);
            head = cur->next;
            cur->next = nullptr;
        }
        while (head != nullptr)
        {
            int cnt = 0;
            ListNode *cur = head;
            while (cnt < num - 1)
            {
                cnt++;
                cur = cur->next;
            }
            res.push_back(head);
            head = cur->next;
            cur->next = nullptr;
        }
        while (res.size() < k)
            res.push_back(nullptr);
        return res;
    }
};
// @lc code=end



int main()
{
    Solution solution;

}
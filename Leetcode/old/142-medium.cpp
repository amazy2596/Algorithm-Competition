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
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *res = new ListNode(0, head);
        ListNode *slow = res, *fast = res;
        while (true)
        {
            slow = slow->next;
            if (fast == nullptr || fast->next == nullptr || fast->next->next == nullptr)
                return nullptr;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        slow = res;
        while (true)
        {
            slow = slow->next;
            fast = fast->next;
            if (slow == fast)
                break;
        }
        return slow;
    }
};
// @lc code=end



int main()
{
    Solution solution;

}
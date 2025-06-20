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
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        ListNode *mid = middle(head);
        ListNode *b = reverse(mid->next);
        mid->next = nullptr;
        head = merge(head, b);
    }

    ListNode* middle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = head, *cur = nullptr, *next = nullptr;
        if (prev != nullptr)
        {
            cur = prev->next;
            if (cur != nullptr)
            {
                next = cur->next;
            }
        }
        if (prev != nullptr)
            prev->next = nullptr;
        while (cur != nullptr)
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            if (next != nullptr)
                next = next->next;
        }
        return prev;
    }

    ListNode *merge(ListNode *a, ListNode *b)
    {
        ListNode *res = a;
        ListNode *temp_a = nullptr, *temp_b = nullptr;
        if (a != nullptr)
            temp_a = a->next;
        if (b != nullptr)
            temp_b = b->next;
        while (a != nullptr && b != nullptr)
        {
            a->next = b;
            a = temp_a;
            if (temp_a != nullptr)
                temp_a = temp_a->next;

            b->next = a;
            b = temp_b;
            if (temp_b != nullptr)
                temp_b = temp_b->next;
        }

        return res;
    }
};
// @lc code=end

int main()
{
    Solution solution;
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
    solution.reorderList(a[0]);
}
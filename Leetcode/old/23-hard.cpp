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
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode;
        auto compare = [](const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> q(compare);
        for (ListNode *list : lists)
        {
            if (list != NULL)
                q.push(list);
        }
        ListNode *cur = head;
        while (!q.empty())
        {
            ListNode *node = q.top();
            q.pop();
            cur->next = node;
            if (node->next != NULL)
                q.push(node->next);
            cur = cur->next;
        }
        return head->next;
        // for (int i = 0; i < lists.size(); i++)
        // {
        //     if (lists[i] == NULL)
        //         lists.erase(lists.begin() + i), i--;
        // }
        // int n = 0;
        // for (int i = 0; i < lists.size(); i++)
        // {
        //     if (i == 0)
        //         head->next = lists[i];
        //     ListNode *cur = lists[i];
        //     while (cur->next != NULL)
        //         cur = cur->next, n++;
        //     n++;
        //     if (i != lists.size() - 1)
        //         cur->next = lists[i + 1];
        // }
        // sort(0, n - 1, head);
        // return head->next;
    }

    // ListNode* get_node(int pos, ListNode *head)
    // {
    //     ListNode *cur = head->next;
    //     for (int i = 0; i < pos; i++)
    //         cur = cur->next;
    //     return cur;
    // }

    // int partition(int l, int r, ListNode *head)
    // {
    //     ListNode *target = get_node(r, head);
    //     int j = l;
    //     ListNode *x = get_node(l, head);
    //     for (ListNode *y = get_node(l, head); y != target; y = y->next)
    //     {
    //         if (y->val < target->val)
    //         {
    //             swap(x->val, y->val);
    //             x = x->next;
    //             j++;
    //         }
    //     }
    //     swap(x->val, target->val);
    //     return j;
    // }

    // void sort(int start, int end, ListNode *head)
    // {
    //     if (start < end)
    //     {
    //         int pivot = partition(start, end, head);

    //         sort(start, pivot - 1, head);
    //         sort(pivot + 1, end, head);
    //     }
    // }
};
// @lc code=end
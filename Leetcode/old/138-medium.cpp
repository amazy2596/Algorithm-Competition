#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;

        for (Node *cur = head; cur != nullptr; cur = cur->next)
        {
            if (mp.find(cur) == mp.end())
                mp[cur] = new Node(cur->val);
        }

        for (Node *cur = head; cur != nullptr; cur = cur->next)
        {
            if (cur->next != nullptr)
                mp[cur]->next = mp[cur->next];
            if (cur->random != nullptr)
                mp[cur]->random = mp[cur->random];
        }

        return mp[head];
    }
};
// @lc code=end



int main()
{
    Solution solution;

}
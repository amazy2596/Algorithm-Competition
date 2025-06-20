#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
        vector<int> nums1 = {1, 2}, nums2 = {3, 4};
        priority_queue<int, vector<int>, less<int>> q;
        priority_queue<int, vector<int>, greater<int>> p;
        for (int i = 0; i < nums1.size(); i++)
        {
            q.push(nums1[i]);
            if (q.size() > p.size() + 1)
            {
                p.push(q.top());
                q.pop();
            }
            if (!p.empty() && q.top() > p.top())
            {
                int a = q.top(), b = p.top();
                q.pop(), p.pop();
                q.push(b), p.push(a);
            }
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            q.push(nums2[i]);
            if (q.size() > p.size() + 1)
            {
                p.push(q.top());
                q.pop();
            }
            if (!p.empty() && q.top() > p.top())
            {
                int a = q.top(), b = p.top();
                q.pop(), p.pop();
                q.push(b), p.push(a);
            }
        }
        double ans = 0;
        if ((nums1.size() + nums2.size()) % 2 == 0)
        {
            double temp = q.top();
            q.pop();
            temp += q.top();
            ans = temp / 2;
        }
        else 
            ans = q.top();
    return 0;
}
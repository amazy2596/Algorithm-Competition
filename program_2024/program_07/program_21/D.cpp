#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<string> q;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        q.push(s);
    }
    while (!q.empty())
    {
        string top = q.top();
        q.pop();
        cout << top[0];
        if (top.length() > 1)
            q.push({top.begin() + 1, top.end()});
    }
    return 0;
}
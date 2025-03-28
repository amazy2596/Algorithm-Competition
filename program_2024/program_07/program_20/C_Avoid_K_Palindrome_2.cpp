#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int n, k, ans = 0;
string s, t;
vector<bool> vis;
unordered_set<string> mp;

int check(string t)
{
    for (int i = 0; i < n - k + 1; i++)
    {
        int l = i;
        int r = i + k - 1;
        bool f = 1;
        while (l < r)
        {
            if (t[l++] == t[r--])
                continue;
            else 
            {
                f = 0;
                break;
            }
        }
        if (f)
            return 0;
    }
    return 1;
}

void dfs()
{
    if (t.length() == n)
    {
        if (mp.find(t) == mp.end())
        {
            ans += check(t);
            mp.insert(t);
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        t.push_back(s[i]);
        dfs();
        vis[i] = 0;
        t.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> k >> s;
    vis.resize(n, 0);
    dfs();
    cout << ans << "\n";
    return 0;
}
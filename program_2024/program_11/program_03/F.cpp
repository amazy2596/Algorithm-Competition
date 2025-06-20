#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> cnt;
    for (int i = 0; i < s.length(); i++)
        cnt[s[i]]++;
    char ch;
    for (auto t : cnt)
    {
        if (k <= t.second)
        {
            ch = t.first;
            break;
        }
        k -= t.second;
    }
    int l = 1, r = 1e6 + 5;
    vector<pair<int, int>> v(n, {-1, -1});
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ch)
        {
            if (i == n - 1)
                v[i] = {i, r--};
            else
            {
                if (s[i] > s[i + 1])
                    v[i] = {i, l++};
                else if (s[i] < s[i + 1])
                    v[i] = {i, r--};
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
        if (v[i].second == -1 && s[i] == ch)
            v[i] = {i, v[i + 1].second};
    vector<pair<int, int>> vv; 
    for (int i = 0; i < n; i++)
        if (s[i] == ch)
            vv.push_back(v[i]);
    sort(vv.begin(), vv.end(), [&](pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    });
    int idx = vv[k - 1].first;
    cout << s[idx];
    for (int i = 0; i < s.length(); i++)
        if (i != idx)
            cout << s[i];
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
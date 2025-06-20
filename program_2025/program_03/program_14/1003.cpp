#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e6 + 5;

void solve()
{
    int n;
    cin >> n; 
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    vector<int> suf(n + 1), fre(N);
    int num = 0;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] != 0)
        {
            if (fre[a[i]] == 0)
                fre[a[i]]++, num++;
        }
        suf[i] = num;
    }
    
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + (a[i] == 0);
    
    int ans = 0;
    vector<int> first(N), vis(N);
    vis[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (vis[a[i]])
            continue;
        if (first[a[i]] != 0)
        {
            int j = first[a[i]];
            if (pre[i] - pre[j - 1] >= 1)
            {
                vis[a[i]] = 1;
                ans += suf[i + 1];
            }
        }
        else 
            first[a[i]] = i;
    }
    cout << ans << "\n";
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
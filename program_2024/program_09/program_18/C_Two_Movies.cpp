#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), vis(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int score_a = 0, score_b = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1 && b[i] != -1)
            score_b += b[i], vis[i] = 1;
        else if (a[i] != -1 && b[i] == -1)
            score_a += a[i], vis[i] = 1;
        else if (a[i] == 1 && b[i] != 1)
            score_a += a[i], vis[i] = 1;
        else if (a[i] != 1 && b[i] == 1)
            score_b += b[i], vis[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        if (a[i] == -1)
        {
            if (score_a >= score_b)
                score_a--;
            else 
                score_b--;
        }
        else if (a[i] == 1)
        {
            if (score_a >= score_b)
                score_b++;
            else 
                score_a++;
        }
    }
    cout << min(score_a, score_b) << "\n";
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
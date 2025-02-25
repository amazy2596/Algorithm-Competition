#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int k;
    cin >> k;
    if (k == 0)
    {
        cout << "0\n";
        return;
    }
    vector<pair<int, int>> ans;
    int sum = 0, cnt = 0, mx = 0, mn = 0, num = 500;
    for (int i = 1; num > 0 && sum < k; i++)
    {
        if (sum + cnt > k)
            break;
        ans.push_back({1, i});
        mx = max(mx, i);
        sum += cnt;
        cnt++;
        num--;
    }

    cnt = 0;
    for (int i = -1; num > 0 && sum < k; i--)
    {
        if (sum + cnt > k)
            break;
        
        ans.push_back({-1, i});
        mn = min(mn, i);
        sum += cnt;
        cnt++;
        num--;
    }

    cnt = 0;
    for (int i = 2; i <= mx && mx != 0; i++)
    {
        if (sum + cnt + 1 > k)
            break;
        
        ans.push_back({2, i});
        sum += cnt + 1;
        cnt++;
        num--;
    }

    for (int i = -2; i >= mn && mx != 0; i--)
    {
        if (num > 0 && sum < k)
        {
            ans.push_back({i, i});
            sum++;
            num--;
        }
    }
    
    cout << ans.size() << "\n";
    for (auto [x, y] : ans)
        cout << x << " " << y << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
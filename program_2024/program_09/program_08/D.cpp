#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int s, n, k;
    cin >> s >> n >> k;
    vector<int> ans;
    if (n < k || k > 1e6)
        cout << "NO\n";
    else if (k == 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            ans.push_back(1);
            s--;
        }
        if (s >= 1)
        {
            ans.push_back(s);
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                cout << ans[i] << " \n"[i == n - 1];
            return;
        }
        else 
        {
            cout << "NO\n";
            return;
        }
    }
    else 
    {
        for (int i = 0; i < k; i++)
        {
            ans.push_back(i);
            s -= i;
        }
        if (s < 0 || (s != 0 && ans.size() == n))
            cout << "NO\n";
        else if (s == 0 && ans.size() == n)
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                cout << ans[i] << " \n"[i == n - 1];
            return;
        }
        else
        {
            if (s == k)
            {
                if (ans.size() == n - 1)
                {
                    cout << "NO\n";
                    return;
                }
                else 
                {
                    bool f = 0;
                    for (int i = 0; i < s; i++)
                    {
                        if (i != k && s - i != k)
                        {
                            ans.push_back(i);
                            ans.push_back(s - i);
                            f = 1;
                            break;
                        }
                    }
                    while (ans.size() < n)
                        ans.push_back(0);
                    if (f)
                    {
                        cout << "YES\n";
                        for (int i = 0; i < n; i++)
                            cout << ans[i] << " \n"[i == n - 1];
                    }
                    else 
                        cout << "NO\n";
                    return;
                }
            }
            else 
            {
                ans.push_back(s);
                while (ans.size() < n)
                    ans.push_back(0);
                cout << "YES\n";
                for (int i = 0; i < n; i++)
                    cout << ans[i] << " \n"[i == n - 1];
                return;
            }
        }
    }
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
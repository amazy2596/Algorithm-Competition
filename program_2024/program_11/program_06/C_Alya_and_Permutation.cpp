#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    deque<int> ans;
    int k = 0;
    if (n % 2 == 1)
    {
        int l = 0;
        for (int i = 0; i <= 20; i++)
        {
            if ((n >> i) & 1)
            {
                l = 1 << i;
                break;
            }
        }
        ans.push_back(l);
        s.erase(l);
        k |= l;
        ans.push_back(l + (l == 1 ? 2 : 1));
        s.erase(l + (l == 1 ? 2 : 1));
        k &= l + (l == 1 ? 2 : 1);
        ans.push_back(n - l);
        s.erase(n - l);
        k |= n - l;
        ans.push_back(n);
        s.erase(n);
        k &= n;
        cout << k << "\n";
        for (auto temp : s)
            cout << temp << " ";
        for (auto a : ans)
            cout << a << " ";
        cout << "\n";
    }
    else if (n % 2 == 0)
    {
        int cnt = 0;
        for (int i = 0; i <= 20; i++)
            if ((n >> i) & 1)
                cnt++;
        if (cnt == 1)
        {
            ans.push_back(1);
            ans.push_back(3);
            ans.push_back(n - 2);
            ans.push_back(n - 1);
            ans.push_back(n);
            s.erase(1);
            s.erase(3);
            s.erase(n - 2);
            s.erase(n - 1);
            s.erase(n);
            k |= 1;
            k &= 3;
            k |= n - 2;
            k &= n - 1;
            k |= n;
            cout << k << "\n";
            for (auto temp : s)
                cout << temp << " ";
            for (auto a : ans)
                cout << a << " ";
            cout << "\n";
        }
        else
        {
            int h = 0;
            for (int i = 20; i >= 0; i--)
            {
                if ((n >> i) == 1)
                {
                    h = 1 << i;
                    break;
                }
            }
            ans.push_back(n);
            ans.push_back(n - 1);
            ans.push_back(h - 1);
            s.erase(n);
            s.erase(n - 1);
            s.erase(h - 1);
            k |= n;
            k &= n - 1;
            k |= h - 1;
            cout << k << "\n";
            for (auto temp : s)
                cout << temp << " ";
            for (auto a : ans)
                cout << a << " ";
            cout << "\n";
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
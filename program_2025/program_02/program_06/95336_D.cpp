#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    if (n > m)
    {
        swap(n, m);
        swap(a, b);
    }
    map<int, int> mp1, mp2;
    for (auto ch : a)
        mp1[ch - 'a']++;
    for (auto ch : b)
        mp2[ch - 'a']++;
    if (n == m)
    {
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            int cnt1 = 0, cnt2 = 0;
            if (mp1.find(i) != mp1.end())
                cnt1 = mp1[i];
            if (mp2.find(i) != mp2.end())
                cnt2 = mp2[i];
            
            ans += max(cnt1, cnt2) - min(cnt1, cnt2);
        }

        cout << ans / 2 << "\n";
    }
    else
    {
        int ans = 0;
        int temp = (m - n) / 2;
        for (int i = 0; i < 26; i++)
        {
            int cnt1 = 0, cnt2 = 0;
            if (mp1.find(i) != mp1.end())
                cnt1 = mp1[i];
            if (mp2.find(i) != mp2.end())
                cnt2 = mp2[i];
            
            if (cnt2 - cnt1 >= 2)
            {
                int mv = (cnt2 - cnt1) / 2;
                mv = min(mv, temp);   
                temp -= mv;
                cnt2 -= mv, cnt1 += mv;

                ans += max(cnt1, cnt2) - min(cnt1, cnt2);
            }
            else 
                ans += max(cnt1, cnt2) - min(cnt1, cnt2);
        }

        cout << (ans - ((n + m) % 2 == 1)) / 2 << "\n";
    }
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
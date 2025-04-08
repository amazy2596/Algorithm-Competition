#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    auto find = [&](int x) -> pair<int, int>
    {
        int l = 0, r = 1e9;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (mid * (mid - 1) / 2 < x)
                l = mid;
            else 
                r = mid - 1;
        }

        return {l, x - (l * (l - 1) / 2)};
    };

    map<int, set<pair<int, int>>> mp;
    auto insert = [&](int idx, int l, int r)
    {
        auto &st = mp[idx];
        while (true)
        {
            auto it = st.lower_bound({l, 0});
            if (it == st.end())
                break;
            if ((*it).first > r + 1)
                break;
            r = max(r, (*it).second);
            st.erase(it);
        }

        while (true)
        {
            auto it = st.upper_bound({l, 0});
            if (it == st.begin())
                break;
            it = prev(it);
            if ((*it).second < l - 1)
                break;
            l = min(l, (*it).first);
            r = max(r, (*it).second);
            st.erase(it);
        }

        st.insert({l, r});
    };

    vector<int> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        auto [x, y] = find(a[i]);
        insert(x, y, y);
    }

    int ans = 0;
    while (mp.size())
    {
        auto &[idx, st] = *mp.rbegin();
        for (auto [l, r] : st)
        {
            if (r > l)
                insert(idx - 1, l, r - 1);
            ans += r - l + 1;
        }
        mp.erase(idx);
    }

    cout << ans << "\n";
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
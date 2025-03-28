#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    l--, r--;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int ans = 1e18l;
    multiset<int> tar, st;
    for (int i = l; i <= r; i++)
        tar.insert(a[i]);

    st = tar;
    for (int i = 0; i < l; i++)
    {
        if (a[i] < *st.rbegin())
        {
            st.extract(*st.rbegin());
            st.insert(a[i]);
        }
    }
    int temp = 0;
    for (auto it : st)
        temp += it;
    ans = min(ans, temp);

    st = tar;
    for (int i = r + 1; i < n; i++)
    {
        if (a[i] < *st.rbegin())
        {
            st.extract(*st.rbegin());
            st.insert(a[i]);
        }
    }
    temp = 0;
    for (auto it : st)
        temp += it;
    
    ans = min(ans, temp);
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
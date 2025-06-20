#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> b(n);
    multiset<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = {a[i], i};
        st.insert(a[i]);
    }

    sort(b.begin(), b.end());
    auto [l, r] = b[0];
    st.extract(l);
    st.insert(l * 2);
    int ans = *st.rbegin() - *st.begin();
    l = r;

    for (auto &[_, i] : b)
    {
        if (l <= i && i <= r)
            continue;
        
        for (int j = l - 1; j >= i; j--)
        {
            st.extract(a[j]);
            st.insert(a[j] * 2);
            ans = min(ans, *st.rbegin() - *st.begin());
        }
        
        l = min(l, i);

        for (int j = r + 1; j <= i; j++)
        {
            st.extract(a[j]);
            st.insert(a[j] * 2);
            ans = min(ans, *st.rbegin() - *st.begin());
        }

        r = max(r, i);
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
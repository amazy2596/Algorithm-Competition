#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1), preA(n + 1), sufB(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    multiset<int> st;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (st.size() < m)
        {
            st.insert(a[i]);
            sum += a[i];
            preA[i] = sum;
            continue;
        }
        
        if (a[i] < (*st.rbegin()))
        {
            int temp = (*st.rbegin());
            sum -= temp;
            sum += a[i];
            st.extract(temp);
            st.insert(a[i]);
        }

        preA[i] = sum;
    }

    st.clear();
    sum = 0;
    for (int i = n; i >= 1; i--)
    {
        if (st.size() < m)
        {
            st.insert(b[i]);
            sum += b[i];
            sufB[i] = sum;
            continue;
        }
        
        if (b[i] < (*st.rbegin()))
        {
            int temp = (*st.rbegin());
            sum -= temp;
            sum += b[i];
            st.extract(temp);
            st.insert(b[i]);
        }

        sufB[i] = sum;
    }

    int ans = INT64_MAX;
    for (int i = m; i <= n - m; i++)
    {
        ans = min(ans, preA[i] + sufB[i + 1]);
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
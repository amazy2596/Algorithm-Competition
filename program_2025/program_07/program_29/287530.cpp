#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

template<typename T>
struct ST 
{
    using _func = function<T(T, T)>;
    vector<vector<T>> a;
    _func op;
    int n;

    ST(vector<T>& input, _func _op = [](T a, T b) { return max(a, b); }) : op(_op) 
    {
        n = input.size() - 1;

        int max_log = __lg(n);
        a.assign(n + 1, vector<T>(max_log + 1, 0));

        for (int i = 1; i <= n; i++) 
            a[i][0] = input[i];

        for (int j = 1; j <= max_log; j++) 
        {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) 
            {
                // [i + 2 ^ (j - 1) - 1, i + 2 ^ j - 1], [i + 2 ^ (j - 1), i + 2 ^ j - 1];
                a[i][j] = op(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) 
    {
        int j = __lg(r - l + 1);
        // [l, l + 2 ^ j - 1], [r - 2 ^ j + 1, r];
        return op(a[l][j], a[r - (1 << j) + 1][j]);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), f(n + 1);
    map<int, vector<int>> mp;
    mp[0].push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = f[i - 1] ^ a[i];
        mp[f[i]].push_back(i);
    }

    auto tmp = [](int a, int b) -> int { return __gcd(a, b); };

    ST<int> st(a, tmp);
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int L = i - 1;
        while (L >= 1)
        {
            int l = 1, r = L;
            int g = st.query(L, i);
            while (l < r)
            {
                int mid = l + r >> 1;
                if (st.query(mid, i) == g)
                    r = mid;
                else 
                    l = mid + 1;
            }

            auto &v = mp[g ^ f[i]];
            int ll = lower_bound(v.begin(), v.end(), l - 1) - v.begin();
            int rr = lower_bound(v.begin(), v.end(), L) - v.begin();

            ans += rr - ll;
            L = l - 1;
        }
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
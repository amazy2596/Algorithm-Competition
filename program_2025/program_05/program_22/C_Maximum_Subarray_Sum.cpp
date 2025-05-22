#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (s[i] == '0')
            a[i] = -inf;
    }

    auto get = [&]()
    {
        int cur = -inf, ans = -inf;
        for (int i = 0; i < n; i++)
        {
            cur = max(0ll, cur) + a[i];
            ans = max(ans, cur);
        }

        return ans;
    };

    int res = get();
    if (res > k)
    {
        cout << "No\n";
        return;
    }

    int x = s.find('0');
    if (x == -1)
    {
        if (res == k)
        {
            cout << "Yes\n";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << "\n";
        }
        else 
            cout << "No\n";
        return;
    }
    
    a[x] = inf;
    res = get();
    a[x] -= (res - k);
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
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
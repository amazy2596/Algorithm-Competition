#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int l, r;
    cin >> l >> r;

    auto check = [&]()
    {
        int a = 0, b = 0;
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] == '0' && s[i] == '1')
                a++;
            else if (s[i - 1] == '1' && s[i] == '0')
                b++;
        }
        return a == b;
    };

    if (check())
    {
        cout << "Y\n";
        return;
    }

    for (int i = l; i <= r; i++)
        s[i] = '0';

    if (check())
    {
        cout << "Yes\n";
        return;
    }

    for (int i = l; i <= r; i++)
        s[i] = '1';

    if (check())
    {
        cout << "Yes\n";
        return;
    }

    int cnt = 0;
    for (int i = l; i <= r; i++)
        s[i] == (cnt++ % 2 == 0 ? '0' : '1');
    
    if (check())
    {
        cout << "Yes\n";
        return;
    }

    cnt = 0;

    for (int i = l; i <= r; i++)
        s[i] == (cnt++ % 2 == 0 ? '1' : '0');

    if (check())
    {
        cout << "Yes\n";
        return;
    }

    cout << "No\n";
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
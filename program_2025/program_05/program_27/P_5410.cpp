#include <bits/stdc++.h>
// #define int long long
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
    string a, b;
    cin >> a >> b;

    vector<int> z(b.length());
    int l = 0, r = 0;
    for (int i = 1; i < b.length(); i++)
    {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);

        while (i + z[i] < b.length() && z[i] < b.length() && b[i + z[i]] == b[z[i]])
            z[i]++;

        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    z[0] = b.length();

    l = 0, r = 0;
    vector<int> p(a.length());
    for (int i = 1; i < a.length(); i++)
    {
        if (i <= r)
            p[i] = min(z[i - l], r - i + 1);
        
        while (i + p[i] < a.length() && p[i] < b.length() && b[p[i]] == a[i + p[i]])
            p[i]++;
        
        if (i + p[i] - 1 > r)
        {
            l = i;
            r = i + p[i] - 1;
        }
    }

    while (p[0] < a.length() && p[0] < b.length() && a[p[0]] == b[p[0]])
        p[0]++;

    long long val1 = 0, val2 = 0;
    for (int i = 0; i < z.size(); i++)
        val1 ^= 1ll * (i + 1) * (z[i] + 1);
    for (int i = 0; i < p.size(); i++)
        val2 ^= 1ll * (i + 1) * (p[i] + 1);

    cout << val1 << "\n" << val2;
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
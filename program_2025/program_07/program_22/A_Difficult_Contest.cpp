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
    string s;
    cin >> s;
    map<int, int> mp;
    for (int i = 0; i < s.length(); i++)
        mp[s[i] - 'A']++;

    while (mp['T' - 'A'])
    {
        cout << 'T';
        mp['T' - 'A']--;
    }

    for (auto [key, val] : mp)
    {
        while (val)
        {
            cout << (char)(key + 'A');
            val--;
        }
    }

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
#include <bits/stdc++.h>
using namespace std;
using uint = uint64_t;
#define int long long

const int inf = 4e18;
int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> a[i], mp[a[i]]++;

    for (auto [key, val] : mp)
    {
        if (mp[key] >= 4)
        {
            cout << "Yes\n";
            return;
        }
        if (mp[key] >= 2)
        {
            for (int i = key + 1; ; i++)
            {
                if (mp.find(i) != mp.end())
                {
                    if (mp[i] == 0)
                        break;
                    if (mp[i] >= 2)
                    {
                        cout << "Yes\n";
                        return;
                    }
                }
                else 
                    break;
            }
        }
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
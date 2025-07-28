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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int cnt = 1, ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] > a[i])
        {
            cnt += i;
            ans += cnt;
        }
        else 
        {
            cnt++;
            ans += cnt;
        }
    }

    cout << ans << "\n";

    // int n = 4;
    // vector<int> p(n);
    // iota(p.begin(), p.end(), 1);
    // do
    // {
    //     bool f = 0;
    //     for (int i = 2; i < n; i++)
    //     {
    //         if (max(p[i - 1], p[i - 2]) <= p[i])
    //         {
    //             f = 1;
    //             break;
    //         }
    //     }
    //     if (f) continue;

    //     int ans = 0;
    //     auto a = p;
    //     for (int i = 0; i < n; i++)
    //         a[i] = -a[i];

    //     vector<int> w(n);
    //     for (int l = 0; l < n; l++)
    //     {
    //         for (int r = 0; r < n; r++)
    //         {
    //             vector<int> tmp;
    //             for (int i = l; i <= r; i++)
    //             {
    //                 if (tmp.empty())
    //                     tmp.push_back(a[i]);
    //                 else 
    //                 {
    //                     auto it = lower_bound(tmp.begin(), tmp.end(), a[i]);
    //                     if (it == tmp.end())
    //                         tmp.push_back(a[i]);
    //                     else 
    //                         *it = a[i];
    //                 }
    //             }
    //             for (int x : tmp)
    //             {
    //                 for (int i = 0; i < n; i++)
    //                 {
    //                     if (x == a[i])
    //                         w[i]++;
    //                 }
    //             }

    //             ans += tmp.size();
    //         }
    //     }

    //     cout << "p: ";
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (p[i] < 10)
    //             cout << " ";
    //         cout << p[i] << " \n"[i == n - 1];
    //     }
    //     cout << "w: ";
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (w[i] < 10)
    //             cout << " ";
    //         cout << w[i] << " ";
    //     }
    //     cout << "ans: " << ans << "\n\n";
    // } while (next_permutation(p.begin(), p.end()));
    
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
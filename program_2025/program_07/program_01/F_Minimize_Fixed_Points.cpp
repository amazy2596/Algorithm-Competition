#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int N = 1e6 + 5;
vector<int> minp(N), prime;

void init()
{
    for (int i = 2; i < N; i++)
    {
        if (minp[i] == 0)
        {
            minp[i] = i;
            prime.push_back(i);
        }

        for (auto p : prime)
        {
            if (i * p >= N)
                break;

            minp[i * p] = p;

            if (minp[i] == p)
                break;
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> vis(n + 1);
    map<int, deque<int>> mp;
    map<int, int> to;

    for (int i = 2; i <= n; i++)
    {
        int x = i;
        int use = 0;
        while (x > 1)
        {
            int tmp = minp[x];
            if (mp[tmp].size() == 1)
            {
                use = 1;
                mp[tmp].push_back(i);
                to[i] = tmp;
                break;
            }
            x /= tmp;
        }

        x = i;
        while (!use && x > 1)
        {
            int tmp = minp[x];
            if (mp[tmp].size() > 1)
            {
                use = 1;
                mp[tmp].push_back(i);
                to[i] = tmp;
                break;
            }
            x /= tmp;
        }

        if (!use)
        {
            mp[minp[i]].push_back(i);
            to[i] = minp[i];
        }
    }

    for (auto &[key, val] : mp)
    {
        val.push_back(val.front());
        val.pop_front();
    }

    vector<int> ans(n + 1);
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        auto &v = mp[to[i]];
        ans[i] = v.front();
        v.pop_front();
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";

    // for (int i = n; i <= n; i++)
    // {
    //     vector<int> a(i + 1);
    //     iota(a.begin() + 1, a.end(), 1);

    //     do
    //     {
    //         int good = 1;
    //         for (int j = 2; j <= i; j++)
    //         {
    //             if (__gcd(a[j], j) == 1)
    //             {
    //                 good = 0;
    //                 break;
    //             }
    //         }

    //         if (good)
    //         {
    //             int temp = 0;
    //             for (int j = 1; j <= i; j++)
    //             {
    //                 if (a[j] == j)
    //                     temp++;
    //             }
    //             cout << "good: " << temp << "\n";
    //             for (int j = 1; j <= i; j++)
    //                 cout << a[j] << " ";
    //             cout << "\n";
    //         }
    //     } while (next_permutation(a.begin() + 1, a.end()));
    // }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
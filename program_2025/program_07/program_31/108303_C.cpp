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
    for (int n = 1; n <= 7; n++)
    {
    cout << "num: " << n << "\n";
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    map<int, map<int, int>> cnt;
    do
    {
        auto tmp = a;
        stack<int> s;
        for (auto x : tmp)
        {
            while (!s.empty() && s.top() > x)
                s.pop();
            s.push(x);
        }
        int siz = s.size();

        deque<int> q;
        while (!s.empty())
            q.push_front(s.top()), s.pop();

        int hash = 0;
        while (!q.empty())
        {
            hash = (hash * 10 + q.front());
            q.pop_front();
        }

        cnt[siz][hash]++;
    } while (next_permutation(a.begin(), a.end()));
    

    for (auto [siz, mp] : cnt)
    {
        cout << "size: " << siz << "\n";
        int sum = 0;
        for (auto [hash, val] : mp)
        {
            cout << "hash: " << hash << " val: " << val << "\n";
            sum += val;
        }
        cout << "sum: " << sum << "\n";
        cout << "\n";
    }
    cout << "\n";
    }
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
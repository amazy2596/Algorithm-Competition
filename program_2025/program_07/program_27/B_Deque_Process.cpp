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

    string ans;
    int l = 1, r = n;
    vector<int> q;
    while (ans.length() < n)
    {
        if (q.empty())
        {
            ans += "L";
            q.push_back(a[l]);
            l++;
            continue;
        }

        int x = a[l], y = a[r], z = q.back();
        if (z > x && z > y)
        {
            if (x < y)
            {
                if (ans.length() < n)
                {
                    ans += "L";
                    q.push_back(a[l]);
                }
                if (ans.length() < n)
                {
                    ans += "R";
                    q.push_back(a[r]);
                }
            }
            else 
            {
                if (ans.length() < n)
                {
                    ans += "R";
                    q.push_back(a[r]);
                }
                if (ans.length() < n)
                {
                    ans += "L";
                    q.push_back(a[l]);
                }
            }
        }
        else if (z < x && z < y)
        {
            if (x > y)
            {
                if (ans.length() < n)
                {
                    ans += "L";
                    q.push_back(a[l]);
                }
                if (ans.length() < n)
                {
                    ans += "R";
                    q.push_back(a[r]);
                }
            }
            else 
            {
                if (ans.length() < n)
                {
                    ans += "R";
                    q.push_back(a[r]);
                }
                if (ans.length() < n)
                {
                    ans += "L";
                    q.push_back(a[l]);
                }
            }
        }
        else
        {
            if (ans.length() < n)
            {
                ans += "R";
                q.push_back(a[r]);
            }
            if (ans.length() < n)
            {
                ans += "L";
                q.push_back(a[l]);
            }
        }

        l++, r--;
    }

    // for (int i = 0; i < q.size(); i++)
        // cout << q[i] << " ";
    // cout << "\n";
    cout << ans << "\n";
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
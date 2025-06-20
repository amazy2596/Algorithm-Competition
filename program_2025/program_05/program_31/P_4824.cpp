#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++)
    {
        while (j && t[i] != t[j])
            j = pi[j - 1];
        if (t[i] == t[j])
            j++;
        pi[i] = j;
    }

    string res;
    vector<int> len;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        int k = 0;
        if (!len.empty())
            k = len.back();

        while (k && t[k] != ch)
            k = pi[k - 1];

        if (t[k] == ch)
            k++;

        res.push_back(ch);
        len.push_back(k);

        if (k == m)
        {
            for (int j = 0; j < m; j++)
            {
                res.pop_back();
                len.pop_back();
            }
        }
    }

    cout << res << "\n";
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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    set<int> s;
    int mex = s.size();
    for (int i = 1; i <= n; i++)
    {
        s.insert(a[i]);
        if (a[i] && mex == s.size())
        {
            cout << "-1\n";
            return;
        }
        mex = s.size();
    }

    int mx = *max_element(s.begin(), s.end());
    if (mx > mex)
    {
        cout << "-1\n";
        return;
    }

    int lacki = -1;
    if (mx == mex)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == mx)
            {
                lacki = i;
                break;
            }
        }
    }

    vector<int> ans(n + 1);
    if (lacki != -1)
    {
        vector<int> b = a;
        sort(b.begin() + 1, b.end());

        b[0] = -1;

        int lacknum = -1;
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == b[i - 1] + 2)
                lacknum = b[i - 1] + 1;
        }

        for (int i = 1; i <= n; i++)
            ans[a[i]] = i;

        ans[lacknum] = lacki;

        cout << mx << "\n";
        for (int i = 1; i <= mx; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    else 
    {
        for (int i = 1; i <= n; i++)
            ans[a[i]] = i;
        cout << mx << "\n";
        for (int i = 1; i <= mx; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
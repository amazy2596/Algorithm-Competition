#include <bits/stdc++.h>
#define int long long
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), idx(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        idx[a[i]] = i;
    }

    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (idx[k] < l || idx[k] > r)
        {
            cout << "-1 ";
            continue;
        }

        int wl = 0, wr = 0, cl = 0, cr = 0, pos = idx[k];
        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (a[mid] == k)
                break;
            
            if (mid < pos)
            {
                if (a[mid] > k)
                    wl++;
                l = mid + 1;
                cl++;
            }
            else 
            {
                if (a[mid] < k)
                    wr++;
                r = mid - 1;
                cr++;
            }
        }

        if (cl > k - 1 || cr > n - k)
        {
            cout << "-1 ";
            continue;
        }

        if (wl <= k - 1 && wr <= n - k)
            cout << 2 * max(wl, wr) << " ";
        else 
            cout << "-1 ";
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
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];

    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    for (int i = 0; i < n; i++)
        cnt += (a[i] == mx);

    if (mx - mn > k + 1 || (mx - mn == k + 1 && cnt > 1))
    // if (mx - mn > k + 1)
        cout << "Jerry\n";
    else 
    {
        if (sum % 2 == 1)
            cout << "Tom\n";
        else 
            cout << "Jerry\n";
    }
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
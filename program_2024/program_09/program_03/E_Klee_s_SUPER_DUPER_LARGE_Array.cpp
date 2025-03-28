#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;

int get(int x)
{
    int a = (k + x) * (x - k + 1) / 2;
    int b = (x + k + n) * (k + n - x - 1) / 2;
    return abs(a - b);
}

void solve()
{
    cin >> n >> k;
    int l = k - 2, r = k + n + 2;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        int lmid = mid - 1;
        int rmid = mid + 1;
        if (l == lmid)
            lmid++;
        if (r == rmid)
            rmid--;
        int a = get(lmid);
        int b = get(rmid);
        if (a > b)
            l = lmid;
        else 
            r = rmid;
    }
    cout << min(get(l), get(r)) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
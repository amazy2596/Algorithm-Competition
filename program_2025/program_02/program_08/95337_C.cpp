#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    string a, b, c;
    cin >> a >> b >> c;

    vector<int> cnt(4);
    for (int i = 0; i < n; i++)
    {
        int temp1 = a[i] - '0', temp2 = b[i] - '0', temp3 = c[i] - '0';
        int idx = temp1 * 2 + temp2;
        if ((temp1 ^ temp2) != temp3)
            cnt[idx]++;
    }

    int sum = cnt[0] + cnt[1] + cnt[2] + cnt[3];
    int maxCount = max(max(cnt[0], cnt[1]), max(cnt[2], cnt[3]));
    if (2 * x <= y)
    {
        cout << x * sum << "\n";
        return;
    }

    int num = min(sum / 2, sum - maxCount);
    cout << y * num + x * (sum - 2 * num) << "\n";
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
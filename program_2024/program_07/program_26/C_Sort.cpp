#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    vector<vector<int>> prefixsum_a(26, vector<int>(n + 1)), prefixsum_b(26, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            prefixsum_a[j][i] = prefixsum_a[j][i - 1];
            prefixsum_b[j][i] = prefixsum_b[j][i - 1];
        }
        prefixsum_a[a[i] - 'a'][i]++;
        prefixsum_b[b[i] - 'a'][i]++;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            int x = prefixsum_a[i][r] - prefixsum_a[i][l - 1];
            int y = prefixsum_b[i][r] - prefixsum_b[i][l - 1];
            ans += abs(x - y);
        }
        cout << ans / 2 << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
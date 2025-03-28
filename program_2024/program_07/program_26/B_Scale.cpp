#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i += k)
    {
        for (int j = 0; j < n; j += k)
        {
            cout << s[i][j];
        }
        cout << "\n";
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
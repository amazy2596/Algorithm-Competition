#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << 0 << "\n";
        return;
    }
    int sum = 0;
    sum += n;
    if (k <= sum)
    {
        cout << 1 << "\n";
        return;
    }
    for (int i = n - 1, j = 2; i >= 1; i--, j += 2)
    {
        sum += i;
        if (k <= sum)
        {
            cout << j << "\n";
            return;
        }
        sum += i;
        if (k <= sum)
        {
            cout << j + 1 << "\n";
            return;
        }
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
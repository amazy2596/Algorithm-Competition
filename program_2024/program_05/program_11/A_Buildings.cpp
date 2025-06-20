#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i && a[i] > a[0])
        {
            cout << i + 1 << "\n";
            break;
        }
        if (i == n - 1)
        {
            cout << -1 << "\n";
            break;
        }
    }
    return 0;
}
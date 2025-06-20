#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        intt ans = 0;
        for (int i = 1, num = 1; i <= n; i++, num += 2)
            ans += i * num;
        cout << ans << " " << 2 * n << "\n";
        for (int i = n; i >= 1; i--)
        {
            cout << 1 << " " << i << " ";
            for (int j = 1; j <= n; j++)
                cout << j << " \n"[j == n];
            cout << 2 << " " << i << " ";
            for (int j = 1; j <= n; j++)
                cout << j << " \n"[j == n];
        }
    }
    return 0;
}
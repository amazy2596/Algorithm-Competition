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
        intt n, a, b;
        cin >> n >> a >> b;
        if (b <= a)
            cout << n * a << "\n";
        else 
        {
            intt k = min(b - a + 1, n);
            cout << ((b - k + 1 + b) * k / 2) + a * (n - k) << "\n";
        }
    }
    return 0;
}
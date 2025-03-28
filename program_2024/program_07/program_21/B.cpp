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
        intt a, b, n;
        cin >> a >> b >> n;
        b /= 2;
        if (n / 3 <= b)
            n %= 3;
        else 
            n -= b * 3;
        if (a >= n)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        int mn = min({a, b, c, d});
        a -= mn, b -= mn, c -= mn, d -= mn;
        if (a == 0)
        {
            if (d > b && c < b)
                cout << "YES\n";
            else 
                cout << "NO\n";
        }
        else if (b == 0)
        {
            if (d > a && c < a)
                cout << "YES\n";
            else 
                cout << "NO\n";
        }
        else if (c == 0)
        {
            if (b > d && a < d)
                cout << "YES\n";
            else 
                cout << "NO\n";
        }
        else if (d == 0)
        {
            if (b > c && a < c)
                cout << "YES\n";
            else 
                cout << "NO\n";
        }
    }
    return 0;
}
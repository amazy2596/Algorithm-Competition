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
        int n, a, b;
        cin >> n >> a >> b;
        if (a * 2 <= b)
            cout << a * n << "\n";
        else 
        {
            if (n % 2 == 0)
                cout << b * (n / 2) << "\n";
            else 
                cout << b * (n / 2) + a << "\n";
        }
    }
    return 0;
}
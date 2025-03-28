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
        int n, m;
        cin >> n >> m;
        if (n < m)
            cout << "No\n";
        else if ((n - m) % 2 == 0)
            cout << "Yes\n";
        else 
            cout << "No\n";
    }
    return 0;
}
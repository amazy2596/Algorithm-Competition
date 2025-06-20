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
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        if ((y - x) % 3 != 0)
            cout << "No\n";
        else 
            cout << "Yes\n";
    }
    return 0;
}
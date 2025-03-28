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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int mn = *min_element(a.begin(), a.end());
        int g = 0;
        for (int i = 0; i < n; i++)
            if (a[i] % mn)
                g = __gcd(g, a[i]);
        bool f = 0;
        for (int i = 0; i < n; i++)
            if (g % a[i] == 0)
            {
                f = 1;
                break;
            }
        cout << (f ? "Yes\n" : "No\n");
    }
    return 0;
}
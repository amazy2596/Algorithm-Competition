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
        intt ans = 0, sum = 0;
        int base = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if (sum > 0)
                ans += sum * base, sum = 0;
        }
    }
    return 0;
}
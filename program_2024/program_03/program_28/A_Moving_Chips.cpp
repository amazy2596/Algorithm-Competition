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
        int l = 0, r = n - 1;
        while (a[l] == 0)
            l++;
        while (a[r] == 0)
            r--;
        int ans = count(a.begin() + l, a.begin() + r, 0);
        cout << ans << endl;
    }
    return 0;
}


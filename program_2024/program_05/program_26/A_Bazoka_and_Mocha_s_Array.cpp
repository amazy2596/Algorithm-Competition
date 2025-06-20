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
        bool f = is_sorted(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            if (is_sorted(a.begin(), a.begin() + i) && is_sorted(a.begin() + i, a.end()) && (a.front() >= a.back()))
            {
                f = 1;
                break;
            }
        }
        cout << (f ? "Yes\n" : "No\n");
    }
    return 0;
}
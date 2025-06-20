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
        int n, k;
        cin >> n >> k;
        map<int, int> mapp;
        bool ok = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mapp[x]++;
            if (mapp[x] >= k)
                ok = 1;
        }
        cout << (ok ? k - 1 : n) << "\n";
    }
    return 0;
}
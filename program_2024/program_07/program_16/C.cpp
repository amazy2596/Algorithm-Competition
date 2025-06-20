#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const intt mod = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    intt ans = 0;
    vector<intt> a(1);
    for (int i = 1, q = 1; q <= n; i++, q++)
    {
        intt t, v;
        cin >> t >> v;
        while (t--)
        {
            i--;
            ans = (ans - i * a[i] + mod) % mod;
            a.pop_back();
        }
        a.push_back(v);
        ans = (ans + i * a[i] + mod) % mod;
        cout << (ans + mod) % mod << "\n";
    }
    return 0;
}
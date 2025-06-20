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
        if (n % 2 == 0)
            cout << (k % n == 0 ? n : k % n) << "\n";
        else 
        {
            int ans = (k + (k - 1) / (n / 2)) % n;
            cout << (ans == 0 ? n : ans) << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt n;
    cin >> n;
    int ans = 0;
    while (n)
    {
        if (n == 2)
            n -= 2;
        else if (n % 2 == 0)
            n /= 2;
        else 
            n -= 1;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
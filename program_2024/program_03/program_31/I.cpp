#include <bits/stdc++.h>
using intt = long long;
using namespace std;

intt gcd(intt a, intt b)
{
    return b ? gcd(b, a % b) : a;
}

intt lcm(intt a, intt b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        intt a, b;
        cin >> a >> b;
        intt ans = lcm(a, b);
        cout << ans << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

intt lcm(int a, int b)
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
        int n;
        cin >> n;
        vector<intt> a(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
            cin >> a[i], mp[a[i]]++;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        cout << n;
    }
    return 0;
}
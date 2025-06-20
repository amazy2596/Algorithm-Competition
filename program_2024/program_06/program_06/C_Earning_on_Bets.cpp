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
        int n;
        cin >> n;
        vector<int> a(n);
        intt mul = 1;
        for (int i = 0; i < n; i++)
            cin >> a[i], mul = lcm(mul, a[i]);
        vector<int> ans(n);
        intt sum = 0;
        for (int i = 0; i < n; i++)
            ans[i] = mul / a[i], sum += ans[i];
        bool check = 1;
        for (int i = 0; i < n; i++)
            if (1ll * ans[i] * a[i] <= sum)
            {
                check = 0;
                break;
            }            
        if (check)
            for (int i = 0; i < n; i++)
                cout << ans[i] << " \n"[i == n - 1];
        else 
            cout << -1 << "\n";
    }
    return 0;
}
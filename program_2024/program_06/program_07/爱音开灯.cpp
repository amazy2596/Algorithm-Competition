#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt n, x;
    cin >> n >> x;
    multiset<int> s;
    for (int i = 1; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            if (i <= n)
                s.insert(i);
            if (i * i != x)
                if (x / i <= n)
                    s.insert(x / i);
        }
    }
    cout << (s.size() % 2 == 0 ? "OFF" : "ON");
    return 0;
}
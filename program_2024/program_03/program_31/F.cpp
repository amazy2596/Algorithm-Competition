#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt n, m;
    cin >> n >> m;
    intt nn = (1 + n) * n / 2, mm = (1 + m) * m / 2;
    nn %= mod, mm %= mod;
    cout << nn * mm % mod;
    return 0;
}
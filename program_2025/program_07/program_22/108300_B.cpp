#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c)
    {
        cout << "0\n\n";
        return;
    }
    if (a == 0 && b == 0)
    {
        cout << "-1\n";
        return;
    }

    vector<int> ans;
    int highA = __lg(a), highB = __lg(b), highC = __lg(c);
    // for (int k = 31; k >= 0; k--)
    // {
        // if (highA == 0 && (a >> k) & 1 == 1)
            // highA = k;
// 
        // if (highB == 0 && (b >> k) & 1 == 1)
            // highB = k;
// 
        // if (highC == 0 && (c >> k) & 1 == 1)
            // highC = k;
    // }

    if (highA < highB)
    {
        a = a ^ b;
        ans.push_back(3);
        highA = highB;
    }
    else if (highA > highB)
    {
        b = b ^ a;
        ans.push_back(4);
        highB = highA;
    }

    int l = highC;
    for (int k = highA; k <= highC; k++)
    {
        if (((a >> highA) & 1) != ((c >> l) & 1))
        {
            a = a ^ b;
            ans.push_back(3);
        }
        if (k < highC)
        {
            a <<= 1;
            ans.push_back(1);
            l--;
        }
    }


    for (int k = highA; k >= 0; k--)
    {
        if (((a >> k) & 1) != ((c >> k) & 1))
        {
            a = a ^ b;
            ans.push_back(3);
        }
        b >>= 1;
        ans.push_back(2);
    }

    b = a ^ b;
    ans.push_back(4);

    // cout << "num: " << a << " " << b << " " << c << "\n";
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
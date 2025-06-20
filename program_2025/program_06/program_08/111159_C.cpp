#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void solve()
{
    int d, p;
    cin >> d >> p;
    // vector<int> a(50);
    // a[1] = 1;
    // cout << a[1] << " ";
    // for (int i = 2; i < 50; i++)
    // {
        // a[i] = (a[i - 1] + d) % p;
        // cout << a[i] << " ";
    // }

    int g = gcd(d, p);
    int circle = p / g;

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if (p == 1)
        {
            if (l == 1 && r == 1)
                cout << "1\n";
            else if (l == 1)
                cout << "2\n";
            else 
                cout << "1\n";
            continue;
        }

        int len = r - l + 1;
        cout << min(len, circle) << "\n";
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
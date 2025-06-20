#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 4e18;
int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (abs(2 - x1) + abs(n - y1) == abs(2 - x2) + abs(n - y2)) 
    {
        cout << "YES\n";
        return;
    }
    else 
    {
        if (x1 == 2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }

        if (x1 == 1)
        {
            if (y1 + 1 == y2 && y2 + 1 < n)
            {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
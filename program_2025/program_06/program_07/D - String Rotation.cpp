#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] > s[i + 1])
        {
            for (int j = i + 2; j < s.length(); j++)
            {
                if (s[i] < s[j])
                {
                    cout << s.substr(0, i);
                    cout << s.substr(i + 1, j - i - 1);
                    cout << s[i];
                    cout << s.substr(j) << "\n";
                    return;
                }
            }
            cout << s.substr(0, i);
            cout << s.substr(i + 1);
            cout << s[i] << "\n";
            return;
        }
    }

    cout << s << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
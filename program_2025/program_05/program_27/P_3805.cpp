#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    string input;
    cin >> input;
    string s = "#";
    for (int i = 0; i < input.length(); i++)
    {
        s.push_back(input[i]);
        s.push_back('#');
    }

    int n = s.length();
    vector<int> p(n);

    int center = 0, r = 0;
    int len = 0, mxCenter = 0;
    for (int i = 0; i < n; i++)
    {
        int mirror = 2 * center - i;
        if (i < r)
            p[i] = min(p[mirror], r - i);

        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && s[i - p[i] - 1] == s[i + p[i] + 1])
            p[i]++;

        if (i + p[i] > r)
        {
            center = i;
            r = i + p[i];
        }

        if (p[i] > len)
        {
            len = p[i];
            mxCenter = i;
        }
    }

    // int start = (mxCenter - len) / 2;
    // cout << input.substr(start, len) << "\n";
    cout << len << "\n";
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
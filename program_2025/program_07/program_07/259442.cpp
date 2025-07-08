#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);

    auto convert = [&](string &t)
    {
        string res;
        int pos = t.find('.');
        while (pos != -1)
        {
            string tmp = t.substr(0, pos);
            int num = 0;
            for (int i = 0; i < tmp.size(); i++)
                num = num * 10 + (tmp[i] - '0');

            string add;
            while (num)
            {
                add += (num % 2) + '0';
                num /= 2;
            }

            while (add.size() < 8)
                add.push_back('0');

            reverse(add.begin(), add.end());
            res += add;

            t = t.substr(pos + 1);
            pos = t.find('.');
        }

        string tmp = t;
        int num = 0;
        for (int i = 0; i < tmp.size(); i++)
            num = num * 10 + (tmp[i] - '0');

        string add;
        while (num)
        {
            add += (num % 2) + '0';
            num /= 2;
        }

        while (add.size() < 8)
            add.push_back('0');

        reverse(add.begin(), add.end());
        res += add;

        return res;
    };

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        s[i] = convert(s[i]);
        // cout << s[i] << "\n";
    }

    auto calc = [&](string &a, string &b)
    {
        string res;
        for (int i = 0; i < min(a.length(), b.length()); i++)
        {
            if (a[i] == b[i])
                res += a[i];
            else 
                return res;
        }

        return res;
    };

    string pre = s[0];
    for (int i = 1; i < n; i++)
        pre = calc(pre, s[i]);

    int cidr = pre.size();
    while (pre.size() < 32)
        pre.push_back('0');

    string ans;
    for (int i = 0; i < 4; i++)
    {
        int num = 0;
        for (int j = 0; j < 8; j++)
        {
            int k = i * 8 + j;
            if (pre[k] == '1')
                num |= (1ll << (7 - j));
        }

        ans += to_string(num);
        if (i != 3)
            ans += '.';
    }

    cout << ans << "/" << cidr << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
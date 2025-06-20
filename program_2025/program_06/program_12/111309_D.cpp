#include <bits/stdc++.h>
#define uint uint64_t
// #define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

const int N = 1e6 + 5;
set<pair<int, int>> s;
vector<int> cnt(N);

void add(int x)
{
    s.erase({cnt[x], x});
    cnt[x]++;
    s.insert({cnt[x], x});
}

void sub(int x)
{
    s.erase({cnt[x], x});
    cnt[x]--;
    if (cnt[x])
        s.insert({cnt[x], x});
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 1; i <= n; i++)
        s.insert({cnt[a[i]], a[i]});

    set<int> ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;

            sub(a[i]), sub(a[j]);
            add(a[i] + 1), add(a[j] - 1);

            ans.insert((*s.rbegin()).second);

            add(a[i]), add(a[j]);
            sub(a[i] + 1), sub(a[j] - 1);
        }
    }

    for (auto x : ans)
        cout << x << " ";
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
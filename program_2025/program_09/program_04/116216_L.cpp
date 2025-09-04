// Problem: 整数商店的购物之旅
// URL: https://ac.nowcoder.com/acm/contest/116216/L
// Author: amazy
// Date: 2025-09-04 20:05:54

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };



void solve()
{
    i64 a, b, x;
    cin >> a >> b >> x;
    
	i64 l = 0, r = 1e9;
	while (l < r)
	{
		i64 mid = (l + r + 1) >> 1;
		i64 fee = a * mid + b * to_string(mid).size();
		if (fee <= x)
			l = mid;
		else 
			r = mid - 1;
	}
	
	cout << l << "\n";
}

int main()
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
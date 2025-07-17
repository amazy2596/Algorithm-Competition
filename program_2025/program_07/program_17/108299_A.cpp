#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;
int qmi(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = 1ll * res * a % mod;
		b >>= 1;
		a = 1ll * a * a % mod;
	}
	return res;
}

void solve(){
	int n;
	cin >> n;

	vector<int> a(1, 0), pre;
	// int idx = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if(i != 1 && x == a.back() && x != -1) {
			continue;
		}
		// idx++;
		a.push_back(x);
	}
	n = a.size() - 1;
	a.push_back(0);
	pre.assign(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1];
		if(a[i] == -1) pre[i]++;
	}

	int cnt = 0;
	int l = 0, r = 0;
	i64 ans = 0;
	for(int i = 1; i <= n + 1; i++) {
		if(a[i] == -1) cnt++;
		if(a[i] == 0) {
			// cout << n << ": "<< i << '\n';
			r = i;
			l++;
			r--;
			if(l <= r && i) {
				// cout << i << ' ' << l << ' ' << r << '\n';
				int low2 = pre[l], high2 = pre[n] - pre[r];
				i64 wai = qmi(2, low2 + high2);
				// cout << wai << '\n';
				i64 res = 0;
				int t = cnt;
				for(int j = l; j <= r; j++) {
					int lcnt = pre[j] - pre[l - 1];
					int rcnt = cnt - lcnt;
					if(a[j] == -1) rcnt--;
					ans += wai * qmi(2, max(0, lcnt - 1)) % mod * qmi(2, rcnt);

					ans %= mod;
				}
				// cout << ans << '\n';

			}


			l = i;
			cnt = 0;
		}
	}

// 	cout << ans << '\n';





}


int main(){
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int T = 1;
	cin >> T;
	while(T--) solve();

	return 0;
}
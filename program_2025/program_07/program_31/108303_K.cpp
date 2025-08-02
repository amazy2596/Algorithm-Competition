#include<bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1), dis(n + 1);
	int ip = 1;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(i != 1) {
			dis[i] = a[i] - a[i - 1];
			if(dis[i]) ip = 0;
		}
	}

	if(ip) {
		cout << 0 << '\n';
		return;
	}
	int w = 0;
	for(int i = 2; i <= n; i++) {
		w = gcd(w, abs(dis[i]));
	}



	vector<int> fac1, facn;
	for(int i = 1; i <= a[1] / i; i++) {
		if(a[1] % i == 0) {
			fac1.push_back(i);
			fac1.push_back(a[1] / i);
		}
	}

	for(int i = 1; i <= a[n] / i; i++) {
		if(a[n] % i == 0) {
			facn.push_back(i);
			facn.push_back(a[n] / i);
		}
	}
	int z = -1;
	int ans = 1;
	for(auto g : fac1) {
		int cnt = 0;
		z = -1;
		for(int i = 2; i <= n; i++) {
			if(dis[i] % g != 0) {
				cnt++;
				if(z == -1) {
					// z = abs(dis[i] % g);
					if(dis[i] < 0) z = abs(dis[i] % g);
					else z = g - dis[i] % g;
				} else {
					// if(g == 3) cout << z - dis[i] << '\n';
					if((-dis[i] + z) % g != 0) cnt++;
				}
			}
		}
		if(cnt <= 2) ans = max(ans, g);
	}
	for(int i = 2; i <= n; i++) dis[i] = -dis[i];
	for(auto g : facn) {
		int cnt = 0;
		z = -1;
		for(int i = n; i >= 2; i--) {
			if(dis[i] % g != 0) {
				cnt++;
				if(z == -1) {
					// z = abs(dis[i] % g);
					if(dis[i] < 0) z = abs(dis[i] % g);
					else z = g - dis[i] % g;
				} else {
					// if(g == 3) cout << z - dis[i] << '\n';
					if((-dis[i] + z) % g != 0) cnt++;
				}
			}
		}
		if(cnt <= 2) ans = max(ans, g);
	}



	cout << max(ans, w) << '\n';





}


int main(){
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int T = 1;
	cin >> T;
	while(T--) solve();

	return 0;
}

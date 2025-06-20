#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
const int MAX_N = 2e5 + 10;

vector<ll> pow2(MAX_N);
vector<ll> inv_pow2(MAX_N);

ll power(ll x, ll y, ll m) 
{
    ll res = 1;
    x %= m;
    while (y > 0) 
    {
        if (y & 1) res = (res * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

void precompute() {
    pow2[0] = 1;
    for (int i = 1; i < MAX_N; i++)
        pow2[i] = (pow2[i-1] * 2) % MOD;
    
    ll inv2 = power(2, MOD-2, MOD);
    inv_pow2[0] = 1;
    for (int i = 1; i < MAX_N; i++)
        inv_pow2[i] = (inv_pow2[i-1] * inv2) % MOD;
}

void solve() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        vector<int> pre_2(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre_2[i+1] = pre_2[i] + (a[i] == 2);
        
        vector<int> ones, threes;
        for (int i = 0; i < n; i++) 
        {
            if (a[i] == 1) ones.push_back(i);
            else if (a[i] == 3) threes.push_back(i);
        }
        
        if (ones.empty() || threes.empty()) 
        {
            cout << 0 << '\n';
            continue;
        }
        
        vector<ll> inv_vals;
        for (int pos : ones) 
        {
            int cnt_2 = pre_2[pos];
            ll inv_val = inv_pow2[cnt_2];
            inv_vals.push_back(inv_val);
        }
        
        vector<ll> prefix_inv(inv_vals.size() + 1, 0);
        for (int i = 0; i < inv_vals.size(); i++)
            prefix_inv[i+1] = (prefix_inv[i] + inv_vals[i]) % MOD;
        
        ll sum_2k = 0;
        ll count_pairs = 0;
        
        for (int j : threes) 
        {
            auto cnt = lower_bound(ones.begin(), ones.end(), j) - ones.begin();
            if (cnt == 0) continue;
            
            ll sum_inv = prefix_inv[cnt];
            int m = pre_2[j];
            ll pow_val = pow2[m];
            ll term = (sum_inv * pow_val) % MOD;
            sum_2k = (sum_2k + term) % MOD;
            count_pairs += cnt;
        }
        
        ll ans = (sum_2k - count_pairs + MOD) % MOD;
        cout << ans << '\n';
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute();
    solve();
    return 0;
}
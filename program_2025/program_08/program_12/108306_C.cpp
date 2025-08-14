#include<bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> deg(n + 1);
    vector<vector<int>> edge(n + 1);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        deg[v]++;
    }

    set<int> st;
    for(int i = 1; i <= n; i++) {
        if(!deg[i]) st.insert(i);
    } 

    vector<int> dp(1 << n, 1e9);
    dp[(1 << n) - 1] = 0;
    auto dfs = [&] (auto self, int status) -> void {
        if(status == (1 << n) - 1) return;
        if(dp[status]) {
            return;
        }

        vector<int> b;
        for(auto it = st.begin(); it != st.end(); it++) {
            b.push_back(*it);
            cout << *it << endl;
        }
        int m = b.size();
        int yuan = status;
        for(int i = 1; i < (1 << m); i++) {
            int z = i;
            int maxtime = 0;
            for(int j = 0; j <= 25; j++) {
                if((z >> j) & 1) {
                    st.erase(b[j]);
                    status += (1 << (b[j] - 1));
                    maxtime = max(maxtime, a[b[j]]);
                    for(auto v : edge[b[j]]) {
                        deg[v]--;
                        if(deg[v] == 0) st.insert(v);
                    }
                }
            }
            // cout << yuan << ' ' << status << endl;
            self(self, status);
            dp[yuan] = min(dp[yuan], dp[status] + maxtime);
            for(int j = 0; j <= 25; j++) {
                if((z >> j) & 1) {
                    st.insert(b[j]);
                    status -= (1 << (b[j] - 1));
                    for(auto v : edge[b[j]]) {
                        if(deg[v] == 0) st.erase(v);
                        deg[v]++;
                    }
                }
            }
        }
    };

    vector<int> b;
    for(auto it = st.begin(); it != st.end(); it++) {
        b.push_back(*it);
    }
    m = b.size();
    int status = 0;
    int yuan = status;
    for(int i = 1; i < (1 << m); i++) {
        int z = i;
        int maxtime = 0;
        for(int j = 0; j <= 25; j++) {
            if((z >> j) & 1) {
                st.erase(b[j]);
                status += (1 << (b[j] - 1));
                maxtime = max(maxtime, a[b[j]]);
                for(auto v : edge[b[j]]) {
                    deg[v]--;
                    if(deg[v] == 0) 
                    {
                        st.insert(v);
                        cout << "sadljf" << v << endl;
                    }
                }
            }
        }
        cout << yuan << ' ' << status << endl;

        dfs(dfs, status);
        dp[yuan] = min(dp[yuan], dp[status] + maxtime);
        for(int j = 0; j <= 25; j++) {
            if((z >> j) & 1) {
                st.insert(b[j]);
                status -= (1 << (b[j] - 1));
                for(auto v : edge[b[j]]) {
                    if(deg[v] == 0) st.erase(v);
                    deg[v]++;
                }
            }
        }
    }


    cout << dp[0];


    
}


int main() {
    // std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int T = 1;
    //cin >> T;
    while (T--) solve();

    return 0;
}
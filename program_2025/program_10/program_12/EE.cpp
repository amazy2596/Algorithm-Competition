#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
vector<int> a(4);
struct info {
    vector<pair<int, int>> z;
    int cost;
};
void solve(){
    int m;
    cin >> m;  
    vector<array<string, 2>> b(m + 1);
    for (int i = 1; i <= m; i++) {
        string h1, h2;
        cin >> h1 >> h2;
        b[i] = {h1, h2};
    }

    auto rev = [&] (int x, int y) {
        for (int i = 1; i <= m; i++) {
            int cur = b[i][x][y] - '0';
            b[i][x][y] = 1 - cur + '0';
        }
    };

    int ans = 1e9;
    vector<info> op;
    info info1;
    info1.z.push_back({0, 0});
    info1.z.push_back({0, 1});
    info1.z.push_back({1, 0});
    info1.z.push_back({1, 1});
    info1.cost = a[3];
    op.push_back(info1);

    // info1 = {};
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            info1 = {};
            info1.z.push_back({i, j});
            info1.cost = a[0];
            op.push_back(info1);
        }
    }

    for (int i = 0; i <= 1; i++) {
        info1 = {};
        for (int j = 0; j <= 1; j++) {
            info1.z.push_back({i, j});
        }
        info1.cost = a[1];
        op.push_back(info1);
    }

    for (int i = 0; i <= 1; i++) {
        info1 = {};
        for (int j = 0; j <= 1; j++) {
            info1.z.push_back({j, i});
        }
        info1.cost = a[2];
        op.push_back(info1);
    }
    
    auto dfs = [&] (auto self, int ce, int sum) -> void {
        if (ce == op.size()) {
            int ip = 1;
            for (int i = 1; i <= m; i++) {
                for (int j = 0; j <= 1; j++) {
                    for (int k = 0; k <= 1; k++) {
                        if (b[i][j][k] == '0') {
                            ip = 0;
                        }
                    }
                }
            }
            // cout << ip << endl;
            if (ip) cout << sum << endl;
            if (ip) ans = min(ans, sum);
            return;
        }
        self(self, ce + 1, sum);

        auto z = op[ce].z;
        auto cost = op[ce].cost;
        for (auto [x, y] : z) {
            rev(x, y);
        }
        self(self, ce + 1, sum + cost);
        for (auto [x, y] : z) {
            rev(x, y);
        }
    };
    dfs(dfs, 0, 0);
    if (ans == 0) {
        cout << min({a[0], a[1], a[2], a[3]}) * 2 << '\n';
    } else {
        cout << ans << '\n';
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Te = 1;
    cin>>Te;
    for (int i = 0; i <= 3; i++) {
        cin >> a[i];
    }
    while(Te --){
        solve();
    }

}
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve() {
    int n, m;
    cin >> n >> m;
    if(gcd(n, m) != 1) {
        cout << "NO\n";
        return;
    }

    vector<vector<int>> a(n + 1, vector<int> (m + 1));
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
    int ip = 0;

    auto dfs = [&] (auto self, int now, int x, int y, int w1, int w2) -> void {
        // cout << now << endl;
        a[x][y] = now;

        if(now == n * m) {
            if(ip) return;
            ip = 1;
            cout << "YES\n";
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    cout << a[i][j] << ' ';
                }
                cout << '\n';
            }
            return;
        }
        w1 = 1 - w1, w2 = 1 - w2;
        for(int c = w1; c < 2; c++) {
            int zx = x + dx[c] * now, zy = y + dy[c] * now;
            zx = ((zx % n) + n) % n;
            zy = ((zy % m) + m) % m;
            if(zx == 0) zx = n;
            // if(zx == n + 1) zx = 1;
            if(zy == 0) zy = m;
            
            if(a[zx][zy]) continue;
            self(self, now + 1, zx, zy, w1, w2);
            return;
        }
        for(int c = w2 + 2; c < 4; c++) {
            int zx = x + dx[c] * now, zy = y + dy[c] * now;
            zx = ((zx % n) + n) % n;
            zy = ((zy % m) + m) % m;
            if(zx == 0) zx = n;
            // if(zx == n + 1) zx = 1;
            if(zy == 0) zy = m;
            
            if(a[zx][zy]) continue;
            self(self, now + 1, zx, zy, w1, w2);
            break;
        }
        
    };
    a[1][1] = 1;
    dfs(dfs, 1, 1, 1, 0, 0);
    if(!ip) cout << "NO\n";
    





    
}


int main() {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int T = 1;
    //cin >> T;
    while (T--) solve();

    return 0;
}
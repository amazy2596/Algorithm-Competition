#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
template<typename T>
struct Cartesian {
    Cartesian() = default;
    Cartesian(const std::vector<T> &v)
        : ls(v.size(), -1), rs(v.size(), -1) {
        std::stack<int> stk;
        for(int i = 1; i < v.size(); ++i) { // 维护下标 1~n
            while(!stk.empty() && v[i] < v[stk.top()]) {
                stk.pop();
            }
            if(stk.empty()) {
                ls[i] = root;
                root = i;
            } else {
                ls[i] = rs[stk.top()];
                rs[stk.top()] = i;
            }
            stk.push(i);
        }
    }
    int root = -1;
    std::vector<int> ls, rs;
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    Cartesian tree(a);  
    auto &ls = tree.ls, &rs = tree.rs;
    i64 ansl = 0, ansr = 0;
    for (int i = 1; i <= n; i++) {
        // cout << ls[i] << endl;
        ansl ^= 1ll * i * ((ls[i] == -1 ? 0 : ls[i]) + 1);
        ansr ^= 1ll * i * ((rs[i] == -1 ? 0 : rs[i]) + 1);
    }

    cout << ansl << ' ' << ansr;





}


int main() {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int T = 1;
    //cin >> T;
    while (T--) solve();

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template<class T>
struct Fenwick {
    int n;
    vector<T> a;
    Fenwick(int n) : n(n), a(n + 1) {};
    void add (int x, const T &v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v;
        }
    }
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i];
        }
        return ans;
    }
    T range(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    Fenwick<int> fena(n + 2), fenb(n + 2);
    int nia = 0, nib = 0;  
    for (int i = 1; i <= n; i++)  {
        cin >> a[i];
        nia += fena.range(a[i] + 1, n);
        fena.add(a[i], 1);
        nia %= 2;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        nib += fenb.range(b[i] + 1, n);
        fenb.add(b[i], 1);
        nib %= 2;
    }

    cout << ((nia + nib) % 2 == 0 ? "B" : "A");
    int ni = nia + nib;
    for (int i = 1; i < n; i++) {
        char z;
        int l, r, d;
        cin >> z >> l >> r >> d;
        d %= (r - l + 1);
        ni += 1ll * (r - l) * d % 2;
        cout << ((ni) % 2 == 0 ? "B" : "A");
    }
    cout << '\n';



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Te = 1;
    cin>>Te;

    while(Te --){
        solve();
    }

}
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    vector<int> ms = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ty = 1349;
    int tm = 6;
    int td = 28;
    string s;
    cin >> s;

    auto isr = [&](int x)
    {
        if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0) return true;
        return false;
    };

    int y = 0;
    for (int i = 0; i < 4; i++) y = y * 10 + s[i] - '0';
    int m = 0;
    for (int i = 5; i < 7; i++) m = m * 10 + s[i] - '0';
    int d = 0;
    for (int i = 8; i < 10; i++) d = d * 10 + s[i] - '0';

    int ny = 1000, nm = 1, nd = 1;
    int ans1 = 0, ans2 = 0;
    for (int i = ny; i < ty; i++)
    {
        if (isr(i)) ans1 += 366;
        else ans1 += 365;
    }
    for (int i = nm; i < tm; i++) ans1 += ms[i] + (isr(ty) && i == 2);
    ans1 += td - 1;

    for (int i = ny; i < y; i++)
    {
        if (isr(i)) ans2 += 366;
        else ans2 += 365;
    }
    for (int i = nm; i < m; i++) ans2 += ms[i] + (isr(y) && i == 2);
    ans2 += d - 1;

    int ans = abs(ans1 - ans2);
    if (ans2 < ans1) cout << "guo qv le " << ans << " day?";
    else if (ans2 == ans1) cout << "jiu shi today.";
    else cout << "hai cha " << ans << " day!";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
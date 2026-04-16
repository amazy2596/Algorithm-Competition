#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int cnt = 0;
    for (int i = 0; i < n; i++) if (a[i] == b[i]) cnt++;

    if (cnt == n) cout << "The Fool of Tarot ak!";
    else if (cnt == 0) cout << "The Fool of Tarot over!";
    else if (cnt >= n / 2 && cnt != n) cout << "The Fool of Tarot Okay!";
    else if (cnt < n / 2 && cnt > 0) cout << "The Fool of Tarot so-so!";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
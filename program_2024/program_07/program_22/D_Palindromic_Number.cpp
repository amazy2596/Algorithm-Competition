#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    intt n;
    cin >> n;
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    intt d = 1;
    while (true)
    {
        int x = (d - 1) / 2;
        intt cnt = 9 * intt (pow(10, x));
        if (n - cnt >= 0)
            n -= cnt, d++;
        else 
            break;
    }
    n--;
    string ans;
    int x = (d - 1) / 2;
    intt temp = intt (pow(10, x)) + n - 1;
    ans = to_string(temp);
    string cur = ans;
    if (d % 2)
        cur.pop_back();
    reverse(cur.begin(), cur.end());
    ans += cur;
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    solve();
    return 0;
}
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<string> t = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
    vector<string> d = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};
    int base = 1984;
    int i = 0, j = 0;
    while (base < 2044)
    {
        string temp = t[i] + d[j];
        if (temp == s)
        {
            cout << base << "\n";
            return;
        }
        i = (i + 1) % 10;
        j = (j + 1) % 12;
        base++;
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
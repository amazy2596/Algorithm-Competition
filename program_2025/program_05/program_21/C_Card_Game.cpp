#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> card_a, card_b;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
            card_a.push_back(i + 1);
        else 
            card_b.push_back(i + 1);
    }

    int cnt = 0;
    for (int a : card_a)
    {
        if (a == n)
        {
            for (int b : card_b)
            {
                if (b == 1)
                {
                    cnt++;
                    break;
                }
            }
        }
        else if (a == 1) 
        {
            for (int b : card_b)
            {
                if (b > 1 && b != n)
                {
                    cnt++;
                    break;
                }
            }
        }
        else 
        {
            for (int b : card_b)
            {
                if (b > a)
                {
                    cnt++;
                    break;
                }
            }
        }
    }

    if (cnt == card_a.size())
        cout << "Bob\n";
    else 
        cout << "Alice\n";
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
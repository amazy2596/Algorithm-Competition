#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int q;
    cin >> q;

    int score = 0, rescore = 0, sum = 0;
    bool f = 0;
    deque<int> norm, rev;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            score += sum;
            score -= norm.back() * norm.size();
            
            rescore -= sum;
            rescore += norm.back() * norm.size();

            norm.push_front(norm.back());
            norm.pop_back();

            rev.push_back(rev.front());
            rev.pop_front();
        }
        else if (op == 2)
        {
            swap(score, rescore);
            swap(norm, rev);
        }
        else if (op == 3)
        {
            int k;
            cin >> k;
            norm.push_back(k);
            rev.push_front(k);
            sum += k;
            score += norm.size() * k;
            rescore += sum;
        }

        cout << score << "\n";
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
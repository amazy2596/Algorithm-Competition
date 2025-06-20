#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        vector<int> q_odd(n + 1), q_even(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mn_que;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> mx_que;
        int mn = 1, mx = n;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0 && i != n)
                mn_que.push({p[i], i});
            else 
                mx_que.push({p[i], i});
        }
        while (!mn_que.empty())
        {
            auto cur = mn_que.top();
            mn_que.pop();
            q_even[cur.second] = mx--;
        }
        while (!mx_que.empty())
        {
            auto cur = mx_que.top();
            mx_que.pop();
            q_even[cur.second] = mn++;
        }
        mn = 1, mx = n;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 1 && i != 1)
                mn_que.push({p[i], i});
            else 
                mx_que.push({p[i], i});
        }
        while (!mn_que.empty())
        {
            auto cur = mn_que.top();
            mn_que.pop();
            q_odd[cur.second] = mx--;
        }
        while (!mx_que.empty())
        {
            auto cur = mx_que.top();
            mx_que.pop();
            q_odd[cur.second] = mn++;
        }
        int ans_even = 0, ans_odd = 0;
        for (int i = 2; i < n; i++)
        {
            if (p[i] + q_even[i] > p[i - 1] + q_even[i - 1] && p[i] + q_even[i] > p[i + 1] + q_even[i + 1])
                ans_even++;
            if (p[i] + q_odd[i] > p[i - 1] + q_odd[i - 1] && p[i] + q_odd[i] > p[i + 1] + q_odd[i + 1])
                ans_odd++;
        }
        if (ans_even > ans_odd)
            for (int i = 1; i <= n; i++)
                cout << q_even[i] << " ";
        else 
            for (int i = 1; i <= n; i++)
                cout << q_odd[i] << " ";
        cout << "\n";
        // cout << ans_even << " " << ans_odd << "\n";
    }
    return 0;
}


// 11  2 10  3 1 12  8  4  5  7  9  6

//  1 12  3 11 8  4  5 10  7  6  2  9

//  8  4 11  3 2 12  1  7  9  5  10 6

// 12 14 13 14 9 16 13 14 12 13 11 15
//    **    **   **    **    ** 

// 19  6 21  6 3 24  9 11 14 12 19 12
//       **      **       **    **
#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    deque<int> q;
    for (int i = 1; i <= n; i++)
        q.push_back(i);
    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] % a[i])
        {
            cout << -1;
            return 0;
        }
        int count = 0;
        while (gcd(a[i - 1], q.front()) != a[i])
        {
            q.push_back(q.front());
            q.pop_front();
            count++;
            if (count > n)
            {
                cout << -1;
                return 0;
            }
        }
        p[i] = q.front();
        q.pop_front();
    }
    for (int i = 1; i <= n; i++)
        cout << p[i] << " ";
    return 0;
}
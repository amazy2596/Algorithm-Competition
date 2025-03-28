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
        int n, k, pb, ps;
        cin >> n >> k >> pb >> ps;
        vector<intt> a(n + 1), p(n + 1);
        vector<intt> b, s;
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int cur = 0, position = p[pb];
        b.push_back(a[pb]);
        while (position != pb)
        {
            cur += a[position];
            b.push_back(a[position]);
            position = p[position];
        }
        cur = 0, position = p[ps];
        s.push_back(a[ps]);
        while (position != ps)
        {
            cur += a[position];
            s.push_back(a[position]);
            position = p[position];
        }
        intt max_b = 0, temp_b = 0;
        for (int i = 0; i < b.size(); i++)
        {
            if (k - i >= 0)
                max_b = max(max_b, temp_b + (k - i) * b[i]);
            temp_b += b[i];
        }
        intt max_s = 0, temp_s = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (k - i >= 0)
                max_s = max(max_s, temp_s + (k - i) * s[i]);
            temp_s += s[i];
        }
        if (max_b == max_s)
            cout << "Draw\n";
        else if (max_b > max_s)
            cout << "Bodya\n";
        else 
            cout << "Sasha\n";
    }
    return 0;
}
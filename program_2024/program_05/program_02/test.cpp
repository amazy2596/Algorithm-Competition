#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v;
    intt ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i == 0)
        {
            ans += x;
            continue;
        }
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (cnt++ < b && v[i] < 0)
            ans -= v[i];
        else if (v.size() - i > a)
            ans -= v[i];
        else 
            ans += v[i];
    }
    cout << ans << endl;
    return 0;
}
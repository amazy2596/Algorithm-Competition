#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b = a;
    sort(b.begin(), b.end());
    bool f = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            f = 1;
            break;
        }
    }
    cout << (f ? n : 0);
    return 0;
}
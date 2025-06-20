#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n = 6;
    vector<int> a(n);
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    double avg = sum / 30;
    if (a[0] < avg)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
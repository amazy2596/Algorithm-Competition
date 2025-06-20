#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    map<int, int> mp;
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    if (mp.size() == 2 && (mp.begin()->second == 2 || mp.begin()->second == 3))
        cout << "YES\n";
    else 
        cout << "NO\n";
    return 0;
}
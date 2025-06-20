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
    while (n--)
    {
        int x;
        cin >> x;
        if (x < 60)
            cout << "WA\n";
        else 
            cout << "AC\n";
    }
    return 0;
}
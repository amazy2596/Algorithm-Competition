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
        if (n % 2 == 1 || n / 2 % 2 == 1)
            cout << "Bing\n";
        else 
            cout << "Bong\n";
    }
    return 0;
}
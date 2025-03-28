#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt x, y, z;
    cin >> x >> y >> z;
    intt temp = 5e18;
    cout << z << " " << temp / z * z;
    return 0;
}
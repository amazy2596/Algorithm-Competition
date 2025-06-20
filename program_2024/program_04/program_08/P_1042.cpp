#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    vector<char> a;
    char ch;
    while (cin >> ch, ch != 'E')
        a.push_back(ch);
    a.push_back('E');
    int w = 0, l = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 'W')
            w++;
        else if (a[i] == 'L')
            l++;
        if ((abs(w - l) >= 2 && w >= 10 && l >= 10) || (w == 11 && l < 10) || (l == 11 && w < 10) || i == a.size() - 1)
        {
            cout << w << ":" << l << "\n";
            w = 0, l = 0;
        }
    }
    cout << endl;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 'W')
            w++;
        else if (a[i] == 'L')
            l++;
        if ((abs(w - l) >= 2 && w >= 20 && l >= 20) || (w == 21 && l < 20) || (l == 21 && w < 20) || i == a.size() - 1)
        {
            cout << w << ":" << l << "\n";
            w = 0, l = 0;
        }
    }
    return 0;
}
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
        int a, b;
        cin >> a >> b;
        double temp = 0.4 * a + 0.6 * b;
        string s = to_string(temp);
        double result = 0;
        for (int i = s.find('.') + 2, j = -2; i > s.find('.'); i--, j++)
            result += (s[i] - '0') * pow(10, j);
        for (int i = s.find('.') - 1, j = 0; i >= 0; i--, j++)
            result += (s[i] - '0') * pow(10, j);
        cout << ceil(result) << "\n";
    }
    return 0;
}
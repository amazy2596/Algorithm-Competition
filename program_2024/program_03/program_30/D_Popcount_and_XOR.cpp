#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int a, b;
    intt num_c, x = 0, y = 0;
    cin >> a >> b >> num_c;
    // vector<int> a(61), b(61), c;
    vector<int> c;
    int count = 0;
    for (int i = 0; i <= 60; i++)
    {
        int temp = num_c >> i & 1;
        if (temp == 1)
            count++;
        c.push_back(temp);
    }
    bool flag = 1;
    if (count % 2 == 0)
    {
        if (a % 2 != 0 && b % 2 == 0)
            flag = 0;
        if (a % 2 == 0 && b % 2 != 0)
            flag = 0;
    }
    else 
    {
        if (a % 2 == 0 && b % 2 == 0)
            flag = 0;
        if (a % 2 == 1 && b % 2 == 1)
            flag = 0;
    }
    if (a + b < count)
        flag = 0;
    for (int i = 0; i <= 60 && flag; i++)
    {
        if (c[i] == 1)
        {
            if (a > b)
            {
                x += 1ll << i;
              a--;
            }
            else if (a <= b)
            {
                y += 1ll << i;
                b--;
            }
            if (a <= 0 || b <= 0)
            {
                flag = 0;
                break;
            }
        }
    }
    if (a != b)
        flag = 0;
    for (int i = 0; i < 60; i++)
    {
        if ((((x >> i) & 1) == 0 && ((y >> i) && 1) == 0) || c[i] == 0)
        // if ((a[i] == 0 && b[i] == 0) || c[i] == 0)
        {
            x += 1ll << i;
            y += 1ll << i;
            // a[i] = 1;
            // b[i] = 1;
            a--;
            b--;
            // 0011101011100011100011010001011100010101010111001010010100110
            // 0011101111111111111110101110100011101010101000110101101011001
            // 0000000100011100011101111111111111111111111111111111111111111
            // 0010100110111101011110111110110111101110111000110101101011001
            // 0001001101011110111101101111101011111011101111111111111111111
        }
        if (a == 0)
            break;
    }
    intt temp = x ^ y;
    if (temp != num_c)
        flag = 0;
    if (flag)
        cout << x << " " << y;
    else 
        cout << -1;
    return 0;
}
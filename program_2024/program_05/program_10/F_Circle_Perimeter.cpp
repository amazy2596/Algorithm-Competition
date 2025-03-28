#include <bits/stdc++.h>
using intt = long long;
using namespace std;

intt r;

bool check_ans(intt x, intt y)
{   
    if (x * x + y * y >= r * r && x * x + y * y < (r + 1) * (r + 1))
        return 1;
    return 0;
}

bool check(intt x, intt y)
{
    if (x * x + y * y >= r * r)
        return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        cin >> r;
        intt ans = 0;
        for (intt i = r; i >= 1; i--)
        {
            intt low = 1, high = r + 2;
            while (low < high)
            {
                intt mid = low + high >> 1;
                if (check(mid, i))
                    high = mid;
                else 
                    low = mid + 1;
            }
            // cout << low << "\n";
            for (intt x = low; x <= r + 1; x++)
            {
                if (check_ans(x, i))
                    ans++;
                else 
                    break;
            }
        }
        // cout << "\n";
        cout << ans * 4 + 4 << "\n";
    }
    return 0;
}
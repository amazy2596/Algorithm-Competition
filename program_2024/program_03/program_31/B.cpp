#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    // const double pi = 3.141;
    int n;
    cin >> n;
    // vector<pair<long double, double>> p(n);
    long double ans_p, ans_a;
    cin >> ans_p >> ans_a;
    long double ans_pi = ans_p / ans_a;
    for (int i = 0; i < n; i++) 
    {
        long double p, a;
        cin >> p >> a;
        if (abs(p / a - M_PI) < abs(ans_pi - M_PI))
            ans_p = p, ans_a = a;
        else if (abs(p / a - M_PI) == abs(ans_pi - M_PI))
        {
            if (p < ans_p)
                ans_p = p, ans_a = a;
        }
    }
    cout << ans_p << " " << ans_a;
    return 0;
}
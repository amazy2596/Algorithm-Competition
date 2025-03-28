#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(500), b(500);
        for (int i = 0; i < 500; i++)
            a[i] = i, b[i] = i;
        int x = 20;
        while (x--)
        {            
            for (int i = 0; i < 30; i++)
                // cout << a[i] << " \n"[i == 39];
                if (a[i] < 10)
                    cout << "  " << a[i] << " ";
                else if (a[i] < 100)
                    cout << " " << a[i] << " ";
                else 
                    cout << a[i] << " ";
            cout << endl;
            for (int i = 0; i < 100; i++)
            {
                if (i == 0)
                    a[i] = b[i] | b[i + 1];
                else 
                    a[i] = b[i - 1] | b[i] | b[i + 1];
            }
            b = a;
        }
        // if (m == 0)
        //     cout << n << "\n";
        // else 
        // {
        //     int x = 0;
        //     while ()
        // }
    }
    return 0;
}
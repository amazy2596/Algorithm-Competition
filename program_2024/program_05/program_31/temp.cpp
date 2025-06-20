#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 5e8;
int a[N];

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    for (int i = 0; i < N; i++)
        a[i] = i;
    cout << a[N - 1];
    return 0;
}
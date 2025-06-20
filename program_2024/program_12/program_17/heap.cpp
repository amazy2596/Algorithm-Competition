#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 5e5 + 5;
int heap[N], tot = 0;

void up(int p)
{
    while (p > 1 && heap[p / 2] < heap[p])
    {
        swap(heap[p / 2], heap[p]);
        p >>= 1;
    }
}

void down(int p)
{
    int t = p;
    if (2 * p < tot && heap[2 * p] > heap[t])
        t = 2 * p;
    if (2 * p + 1 < tot && heap[2 * p + 1] > heap[t])
        t = 2 * p + 1;
    if (t != p)
    {
        swap(heap[p], heap[t]);
        down(t);
    }
}

void push(int x)
{
    heap[++tot] = x;
    up(tot);
}

void pop()
{
    heap[1] = heap[tot];
    tot--;
    down(1);
}

int top()
{
    return heap[1];
}

bool empty()
{
    return tot == 0;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        push(x);
    }
    while (!empty())
    {
        cout << top() << " ";
        pop();
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

void insertsort(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void shellsort(vector<int> &a)
{
    int n = a.size();
    for (int d = n / 2; d > 0; d /= 2)
    {
        for (int i = d; i < n; i++)
        {
            int key = a[i];
            int j = i - d;
            while (j >= 0 && a[j] > key)
            {
                a[j + d] = a[j];
                j -= d;
            }
            a[j + d] = key;
        }
    }
}

void bubblesort(vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = 0; j < a.size() - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void quicksort(vector<int> &a, int l, int r)
{
    if (r <= l) return;
    int pivot = a[l];
    int i = l, j = r;
    while (i < j)
    {
        while (i < j && a[j] >= pivot) j--;
        a[i] = a[j];
        while (i < j && a[i] < pivot) i++;
        a[j] = a[i];
    }
    a[i] = pivot;

    quicksort(a, l, i - 1);
    quicksort(a, i + 1, r);
}

void selectsort(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        int idx = i;
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[j] < a[idx]) idx = j;
        }
        if (i != idx) swap(a[i], a[idx]);
    }
}

void heapsort(vector<int> &a)
{
    // 0-index 
    // l -> node * 2 + 1
    // r -> node * 2 + 2;

    int n = a.size() - 1;
    // auto up = [&](int i)
    // {
    //     while ((i - 1) / 2 >= 1 && a[(i - 1) / 2] < a[i])
    //     {
    //         swap(a[(i - 1) / 2], a[i]);
    //         i = (i - 1) / 2;
    //     }
    // };

    auto down = [&](int i)
    {
        while (true)
        {
            int l = i * 2 + 1, r = i * 2 + 2, t = i;
            if (l <= n && a[l] > a[t]) t = l;
            if (r <= n && a[r] > a[t]) t = r;
            if (t == i) break;
            swap(a[t], a[i]);
            i = t;
        }
    };

    // auto push = [&](int x)
    // {
    //     a[++n] = x;
    //     up(n);
    // };

    // auto pop = [&]()
    // {
    //     a[0] = a[n--];
    //     down(0);
    // };

    // auto top = [&]()
    // {
    //     return a[0];
    // };

    for (int i = n / 2 - 1; i >= 0; i--) down(i);
    for (int i = a.size() - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        n--;
        down(0);
    }
}

void mergesort(vector<int> &a, int l, int r)
{
    if (r <= l) return;
    int mid = (l + r) / 2;
    mergesort(a, l, mid);
    mergesort(a, mid + 1, r);

    vector<int> c;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j]) c.push_back(a[i]), i++;
        else c.push_back(a[j]), j++;
    }

    while (i <= mid) c.push_back(a[i]), i++;
    while (j <= r) c.push_back(a[j]), j++;

    for (int i = 0; i < c.size(); i++) a[i + l] = c[i];
}

void radixsort(vector<int> &a)
{
    int circle = 0, mx = 0;
    for (int i = 0; i < a.size(); i++) mx = max(mx, a[i]);
    while (mx > 0) circle++, mx /= 10;

    for (int k = 0; k < circle; k++)
    {
        vector<vector<int>> bucket(10);
        for (int i = 0; i < a.size(); i++) 
        {
            int key = a[i];
            for (int j = 0; j < k; j++) key /= 10;
            bucket[key % 10].push_back(a[i]);
        }
        a.clear();
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < bucket[i].size(); j++)
            {
                a.push_back(bucket[i][j]);
            }
        }
    }
}

void countingsort(vector<int> &a, int n)
{
    vector<int> cnt(2 * n + 1), pre(2 * n + 1);
    for (int i = 0; i < a.size(); i++) cnt[a[i] + n]++;
    pre[0] = cnt[0];
    for (int i = 1; i < 2 * n + 1; i++) pre[i] = pre[i - 1] + cnt[i];
    vector<int> b(a.size());
    for (int i = a.size() - 1; i >= 0; i--)
    {
        pre[a[i] + n]--;
        b[pre[a[i] + n]] = a[i];
    }
    a = b;
}

void solve()
{
    vector<int> a = {8, 5, 3, 7, 1, 4, 9, 2, 6};
    // insertsort(a);
    // shellsort(a);
    // bubblesort(a);
    // quicksort(a, 0, a.size() - 1);
    // mergesort(a, 0, a.size() - 1);
    heapsort(a);
    // radixsort(a);
    // countingsort(a, 100);
    for (auto x : a) cout << x << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
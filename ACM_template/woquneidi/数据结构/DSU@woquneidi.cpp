struct DSU
{
    vector<int> f, siz;

    DSU(int n) : f(n + 1), siz(n + 1, 1)
    {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x)
    {
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (siz[x] < siz[y])
            swap(x, y);

        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};
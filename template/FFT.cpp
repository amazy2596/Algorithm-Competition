#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

using Complex = complex<double>;
const double PI = acos(-1.0);

struct FTT
{
    vector<int> rev;
    vector<Complex> roots {Complex(0, 0), Complex(1, 0)};

    FTT() {}

    void dft(vector<Complex> &a, bool invert)
    {
        int n = a.size();

        if (rev.size() != n) 
        {
            rev.resize(n);
            int k = __builtin_ctz(n) - 1;
            for (int i = 0; i < n; i++)
                rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << k);
        }
        for (int i = 0; i < n; i++) 
        {
            if (rev[i] < i) 
            {
                swap(a[i], a[rev[i]]);
            }
        }

        if (roots.size() < n) 
        {
            int k = __builtin_ctz(roots.size());
            roots.resize(n);
            while ((1 << k) < n) 
            {
                double ang = PI / (1 << k);
                Complex e(cos(ang), sin(ang));
                for (int i = 1 << (k - 1); i < (1 << k); i++) 
                {
                    roots[2 * i] = roots[i];
                    roots[2 * i + 1] = roots[i] * e;
                }
                k++;
            }
        }

        for (int len = 2; len <= n; len <<= 1)
        {
            for (int i = 0; i < n; i += len)
            {
                for (int j = 0; j < len / 2; j++)
                {
                    Complex w = roots[j + len / 2];
                    if (invert) w = conj(w);

                    Complex u = a[i + j];
                    Complex v = w * a[i + j + len / 2];
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                }
            }
        }

        if (invert)
        {
            for (auto &x : a)
            {
                x /= n;
            }
        }
    }

    vector<int> mul(const vector<int> &a, const vector<int> &b)
    {
        int tot = a.size() + b.size() - 1;
        if (tot <= 0) return {};

        if (tot < 128) 
        {
            vector<int> c(tot, 0);
            for (int i = 0; i < a.size(); i++) 
            {
                for (int j = 0; j < b.size(); j++) 
                {
                    c[i + j] += a[i] * b[j];
                }
            }
            return c;
        }

        vector<Complex> fa(a.begin(), a.end());
        vector<Complex> fb(b.begin(), b.end());

        int n = 1;
        while (n < tot) n <<= 1;

        fa.resize(n);
        fb.resize(n);

        dft(fa, false);
        dft(fb, false);

        for (int i = 0; i < n; i++)
            fa[i] *= fb[i];

        dft(fa, true);

        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = round(fa[i].real());

        res.resize(tot);
        return res;
    }

    void print_poly(const vector<int> &p)
    {
        bool first_term = true;
        for (int i = p.size() - 1; i >= 0; --i) 
        {
            if (p[i] != 0) 
            {
                if (!first_term)
                    cout << " + ";
                first_term = false;

                cout << p[i];
                if (i > 1)
                    cout << "x^" << i;
                else if (i == 1)
                    cout << "x";
            }
        }
        if (first_term)
            cout << 0;
    }

} ftt;

void solve()
{

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
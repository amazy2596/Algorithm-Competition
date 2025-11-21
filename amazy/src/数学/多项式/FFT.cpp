#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

using Complex = complex<double>;
const double PI = acos(-1.0);

struct FTT
{
    vector<int> rev;
    vector<Complex> roots {Complex(0, 0), Complex(1, 0)};
    FTT() {}

    /**
     * @brief 执行快速傅里叶变换 (FFT) 或其逆变换 (IFFT)。
     *        采用 Cooley-Tukey 算法，在原数组上进行变换（in-place）。
     * @param a 要变换的多项式系数向量（复数形式）。其大小必须是2的幂。
     * @param invert 一个布尔值，`false` 表示执行正向 FFT, `true` 表示执行逆向 IFFT。
     */
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

    /**
     * @brief 使用 FFT 计算两个多项式的乘积（卷积）。
     * @param a 第一个多项式 A(x) 的系数向量。
     * @param b 第二个多项式 B(x) 的系数向量。
     * @return 返回表示乘积多项式 C(x) = A(x) * B(x) 的系数向量。
     * @note 对于小规模输入（结果次数小于128），会回退到 O(n^2) 的朴素乘法以避免 FFT 的常数开销。
     */
    vector<i64> mul(const vector<i64> &a, const vector<i64> &b)
    {
        int siz_a = a.size();
        int siz_b = b.size();
        int tot = siz_a + siz_b - 1;
        if (tot <= 0) return {};

        if (tot < 128) 
        {
            vector<i64> c(tot, 0);
            for (int i = 0; i < siz_a; i++) 
            {
                for (int j = 0; j < siz_b; j++) 
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

        vector<i64> res(n);
        for (int i = 0; i < n; i++)
            res[i] = round(fa[i].real());

        res.resize(tot);
        return res;
    }

    /**
     * @brief 以可读的数学格式打印多项式。
     * @param p 要打印的多项式的系数向量。例如 {4, 23, 22, 15} 会被打印为 "15x^3 + 22x^2 + 23x + 4"。
     */
    void print_poly(const vector<i64> &p)
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

} fft;
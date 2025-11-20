#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

struct BigInt {
    static const int base = 1000000000; // 1e9
    vector<int> a;  // 小端：a[0] 是最低位
    int sign;       // 1 或 -1

    // ===== 构造函数 =====
    BigInt(i64 v = 0) { *this = v; }
    BigInt(const string &s) { fromString(s); }
    BigInt& operator=(i64 v) {
        a.clear();
        sign = 1;
        if (v < 0) {
            sign = -1;
            v = -v;
        }
        if (v == 0) return *this;
        while (v > 0) {
            a.push_back((v % base));
            v /= base;
        }
        return *this;
    }

    // ===== 辅助函数 =====
    bool isZero() const { return a.empty(); }

    void trim() {
        while (!a.empty() && a.back() == 0) a.pop_back();
        if (a.empty()) sign = 1;
    }

    void fromString(const string &s) {
        a.clear();
        sign = 1;
        int pos = 0;
        int n = s.size();
        while (pos < n && isspace(s[pos])) pos++;
        if (pos < n && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-') sign = -1;
            pos++;
        }
        string t;
        for (int i = pos; i < n; ++i) {
            if (isdigit(s[i])) t.push_back(s[i]);
        }
        if (t.empty()) {
            sign = 1;
            return;
        }
        for (int i = t.size(); i > 0; i -= 9) {
            int l = i - 9;
            if (l < 0) l = 0;
            int x = 0;
            for (int j = l; j < i; ++j) x = x * 10 + (t[j] - '0');
            a.push_back(x);
        }
        trim();
    }

    static int absCmp(const BigInt &x, const BigInt &y) {
        int nx = x.a.size();
        int ny = y.a.size();
        if (nx != ny) return nx < ny ? -1 : 1;
        for (int i = nx - 1; i >= 0; --i) {
            if (x.a[i] != y.a[i])
                return x.a[i] < y.a[i] ? -1 : 1;
        }
        return 0;
    }

    static BigInt absAdd(const BigInt &x, const BigInt &y) {
        BigInt r;
        int carry = 0;
        int nx = x.a.size();
        int ny = y.a.size();
        int n = nx > ny ? nx : ny;
        r.a.resize(n);
        for (int i = 0; i < n || carry; ++i) {
            if (i == r.a.size()) r.a.push_back(0);
            i64 cur = carry;
            if (i < nx) cur += x.a[i];
            if (i < ny) cur += y.a[i];
            r.a[i] = (cur % base);
            carry = (cur / base);
        }
        r.trim();
        return r;
    }

    // 要求 |x| >= |y|
    static BigInt absSub(const BigInt &x, const BigInt &y) {
        BigInt r;
        r.a = x.a;
        int carry = 0;
        int ny = y.a.size();
        for (int i = 0; i < ny || carry; ++i) {
            i64 cur = r.a[i] - (i < ny ? (i64)y.a[i] : 0) - carry;
            if (cur < 0) {
                cur += base;
                carry = 1;
            } else {
                carry = 0;
            }
            r.a[i] = cur;
        }
        r.trim();
        return r;
    }

    static BigInt mulSmall(const BigInt &x, int m) {
        if (m == 0 || x.isZero()) return BigInt(0);
        BigInt r;
        r.sign = x.sign;
        if (m < 0) {
            r.sign = -r.sign;
            m = -m;
        }
        i64 carry = 0;
        int nx = x.a.size();
        r.a.resize(nx);
        for (int i = 0; i < nx; ++i) {
            i64 cur = carry + (i64)x.a[i] * m;
            r.a[i] = (cur % base);
            carry = cur / base;
        }
        while (carry) {
            r.a.push_back((carry % base));
            carry /= base;
        }
        r.trim();
        return r;
    }

    static void divmod(const BigInt &a1, const BigInt &b1, BigInt &q, BigInt &r) {
        BigInt a = a1; a.sign = 1;
        BigInt b = b1; b.sign = 1;

        if (a.isZero() || absCmp(a, b) < 0) {
            q = BigInt(0);
            r = a1;
            return;
        }

        int na = a.a.size();
        q = BigInt(0);
        q.a.assign(na, 0);
        q.sign = 1;
        r = BigInt(0);

        for (int i = na - 1; i >= 0; --i) {
            if (!r.isZero()) r = mulSmall(r, base);
            if (a.a[i] != 0) {
                BigInt t(a.a[i]);
                t.sign = 1;
                r = absAdd(r, t);
            }

            int left = 0, right = base - 1, best = 0;
            while (left <= right) {
                int mid = (left + right) >> 1;
                BigInt t = mulSmall(b, mid);
                int c = absCmp(t, r);
                if (c <= 0) {
                    best = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (best > 0) {
                BigInt t = mulSmall(b, best);
                r = absSub(r, t);
            }
            q.a[i] = best;
        }

        q.trim();
        r.trim();

        if (q.isZero()) q.sign = 1;
        else q.sign = a1.sign * b1.sign;

        if (r.isZero()) r.sign = 1;
        else r.sign = a1.sign;
    }

    // ===== 运算符重载 =====
    auto operator<=>(const BigInt& other) const {
        if (sign != other.sign) return sign <=> other.sign;
        int nx = a.size(), ny = other.a.size();
        if (nx != ny) return (sign == 1 ? nx <=> ny : ny <=> nx);
        for (int i = nx - 1; i >= 0; --i) {
            if (a[i] != other.a[i]) {
                return (sign == 1 ? a[i] <=> other.a[i] : other.a[i] <=> a[i]);
            }
        }
        return strong_ordering::equal;
    }
    bool operator==(const BigInt& other) const = default;

    friend BigInt operator-(const BigInt &x) {
        BigInt r = x;
        if (!r.isZero()) r.sign = -r.sign;
        return r;
    }

    friend BigInt operator+(const BigInt &x, const BigInt &y) {
        if (x.sign == y.sign) {
            BigInt r = absAdd(x, y);
            r.sign = x.sign;
            if (r.isZero()) r.sign = 1;
            return r;
        } else {
            int c = absCmp(x, y);
            if (c == 0) return BigInt(0);
            if (c > 0) {
                BigInt r = absSub(x, y);
                r.sign = x.sign;
                if (r.isZero()) r.sign = 1;
                return r;
            } else {
                BigInt r = absSub(y, x);
                r.sign = y.sign;
                if (r.isZero()) r.sign = 1;
                return r;
            }
        }
    }

    friend BigInt operator-(const BigInt &x, const BigInt &y) {
        return x + (-y);
    }

    friend BigInt operator*(const BigInt &x, const BigInt &y) {
        if (x.isZero() || y.isZero()) return BigInt(0);
        BigInt r;
        r.sign = x.sign * y.sign;
        int nx = x.a.size();
        int ny = y.a.size();
        r.a.assign(nx + ny, 0);
        for (int i = 0; i < nx; ++i) {
            i64 carry = 0;
            for (int j = 0; j < ny || carry; ++j) {
                i64 cur = r.a[i + j] + carry;
                if (j < ny) cur += (i64)x.a[i] * y.a[j];
                r.a[i + j] = (cur % base);
                carry = cur / base;
            }
        }
        r.trim();
        if (r.isZero()) r.sign = 1;
        return r;
    }

    friend BigInt operator/(const BigInt &x, const BigInt &y) {
        BigInt q, r;
        divmod(x, y, q, r);
        return q;
    }

    friend BigInt operator%(const BigInt &x, const BigInt &y) {
        BigInt q, r;
        divmod(x, y, q, r);
        return r;
    }

    // ===== 流重载 =====
    friend istream& operator>>(istream &is, BigInt &v) {
        string s;
        is >> s;
        v.fromString(s);
        return is;
    }

    friend ostream& operator<<(ostream &os, const BigInt &v) {
        if (v.isZero()) {
            os << 0;
            return os;
        }
        if (v.sign < 0) os << '-';
        os << v.a.back();
        char buf[16];
        for (int i = v.a.size() - 2; i >= 0; --i) {
            snprintf(buf, sizeof(buf), "%09d", v.a[i]);
            os << buf;
        }
        return os;
    }
};

void solve()
{
    string A, B, C, X, Y, D;
    cin >> A >> B >> C >> X >> Y >> D;

    BigInt a(A), b(B), c(C), x(X), y(Y), d(D);
    vector<BigInt> ans;

    ans.push_back(((d + x - BigInt("1")) / x * a));
    if (x < d || d == x)
    {
        auto q = d / x;
        auto r = d % x;
        auto res = q * a;
        auto rem = min(r, q * y);
        ans.push_back(res + rem * b + (r - rem) * c);
        rem = min(r, y);
        ans.push_back((res + rem * b + (r - rem) * c));
    }

    if (x + y < d || x + y == d)
    {
        auto q = d / (x + y);
        auto r = d % (x + y);
        auto res = q * (a + b * y);
        ans.push_back(res + r * c);

        if (r != BigInt("0")) 
        { 
            // cout << q << " " << r << " " << res << "\n";
            // cout << r - x << " " << -q * y << "\n";
            ans.push_back(res + a + b * max(r - x, -q * y));
        }
    }

    ans.push_back(a + b * min(max(d - x, BigInt("0")), y) + c * max(d - x - y, BigInt("0")));
    cout << *min_element(ans.begin(), ans.end()) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while   (T--)
        solve();
    return 0;
}
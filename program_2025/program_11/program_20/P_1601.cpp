// Problem: A+B Problem（高精）
// URL: https://www.luogu.com.cn/problem/P1601
// Author: amazy
// Date: 2025-11-20 11:13:53

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

ostream& operator<<(ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}

struct BigInt {
    static const int BASE = 1e9;
    vector<int> z;
    int sign;

    BigInt(i64 v = 0) {
        sign = 1;
        if (v < 0) { sign = -1; v = -v; }
        if (v == 0) z.push_back(0);
        while (v > 0) {
            z.push_back(v % BASE);
            v /= BASE;
        }
    }

    BigInt(const string &s) {
        sign = 1;
        z.clear();
        int pos = 0;
        if (!s.empty() && (s[0] == '-' || s[0] == '+')) {
            if (s[0] == '-') sign = -1;
            pos = 1;
        }
        for (int i = s.size(); i > pos; i -= 9) {
            int start = max(pos, i - 9);
            z.push_back(stoi(s.substr(start, i - start)));
        }
        trim();
    }

    void trim() {
        while (z.size() > 1 && z.back() == 0) z.pop_back();
        if (z.empty()) { z = {0}; sign = 1; }
    }

    static bool absLess(const BigInt &a, const BigInt &b) { // 绝对值比较
        if (a.z.size() != b.z.size()) return a.z.size() < b.z.size();
        for (int i = a.z.size() - 1; i >= 0; --i) {
            if (a.z[i] != b.z[i]) return a.z[i] < b.z[i];
        }
        return false;
    }

    auto operator<=>(const BigInt &o) const {
        if (sign != o.sign) return sign <=> o.sign;
        if (z.size() != o.z.size()) {
            return (sign == 1) ? z.size() <=> o.z.size() : o.z.size() <=> z.size();
        }
        for (int i = z.size() - 1; i >= 0; --i) {
            if (z[i] != o.z[i]) {
                return (sign == 1) ? z[i] <=> o.z[i] : o.z[i] <=> z[i];
            }
        }
        return strong_ordering::equal;
    }
    
    bool operator==(const BigInt &o) const = default;

    BigInt operator-() const {
        BigInt res = *this;
        if (res.z.size() > 1 || res.z[0] != 0) res.sign = -res.sign;
        return res;
    }

    friend BigInt operator+(BigInt a, BigInt b) {
        if (a.sign != b.sign) return a - (-b); // 异号转减
        BigInt res; res.sign = a.sign; res.z.clear(); // 同号相加
        i64 carry = 0;
        for (int i = 0; i < max(a.z.size(), b.z.size()) || carry; ++i) {
            i64 sum = carry + (i < a.z.size() ? a.z[i] : 0) + (i < b.z.size() ? b.z[i] : 0);
            res.z.push_back(sum % BASE);
            carry = sum / BASE;
        }
        return res;
    }

    friend BigInt operator-(BigInt a, BigInt b) {
        if (a.sign != b.sign) return a + (-b); // 异号转加
        if (absLess(a, b)) { // 同号相减：确保大减小
            return -(b - a); 
        }
        BigInt res; res.sign = a.sign; res.z.clear();
        i64 borrow = 0;
        for (int i = 0; i < a.z.size(); ++i) {
            i64 diff = a.z[i] - borrow - (i < b.z.size() ? b.z[i] : 0);
            if (diff < 0) { diff += BASE; borrow = 1; }
            else borrow = 0;
            res.z.push_back(diff);
        }
        res.trim();
        return res;
    }

    friend BigInt operator*(const BigInt &a, const BigInt &b) {
        if ((a.z.size() == 1 && a.z[0] == 0) || (b.z.size() == 1 && b.z[0] == 0)) return 0;
        BigInt res; 
        res.z.assign(a.z.size() + b.z.size(), 0);
        res.sign = a.sign * b.sign;
        for (int i = 0; i < a.z.size(); ++i) {
            i64 carry = 0;
            for (int j = 0; j < b.z.size() || carry; ++j) {
                i64 cur = res.z[i + j] + a.z[i] * 1LL * (j < b.z.size() ? b.z[j] : 0) + carry;
                res.z[i + j] = cur % BASE;
                carry = cur / BASE;
            }
        }
        res.trim();
        return res;
    }

    friend pair<BigInt, BigInt> div_mod(const BigInt &a, const BigInt &b) {
        if (absLess(a, b)) return {0, a};
        BigInt q, r;
        q.z.resize(a.z.size());
        q.sign = a.sign * b.sign;
        r.sign = 1; // 计算过程中余数视为正数
        BigInt absB = b; absB.sign = 1; // 使用 BigInt 的绝对值进行计算
        for (int i = a.z.size() - 1; i >= 0; --i) {
            r.z.insert(r.z.begin(), a.z[i]); 
            r.trim();
            int left = 0, right = BASE - 1, best = 0; // 二分试商 (0 ~ BASE-1)
            while (left <= right) {
                int mid = (left + right) / 2;
                if (absB * BigInt(mid) <= r) {
                    best = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            q.z[i] = best;
            r = r - absB * BigInt(best);
        }
        
        q.trim();
        r.sign = a.sign; // 余数符号跟随被除数
        if (r.z.size() == 1 && r.z[0] == 0) r.sign = 1;
        return {q, r};
    }

    friend BigInt operator/(const BigInt &a, const BigInt &b) { return div_mod(a, b).first; }
    friend BigInt operator%(const BigInt &a, const BigInt &b) { return div_mod(a, b).second; }

    friend istream& operator>>(istream &is, BigInt &v) {
        string s; is >> s; v = s; return is;
    }
    friend ostream& operator<<(ostream &os, const BigInt &v) {
        if (v.sign == -1 && !(v.z.size() == 1 && v.z[0] == 0)) os << '-';
        os << (v.z.empty() ? 0 : v.z.back());
        for (int i = (int)v.z.size() - 2; i >= 0; --i)
            os << setfill('0') << setw(9) << v.z[i];
        return os;
    }
};

void solve()
{
    BigInt a, b;
    cin >> a >> b;
    cout << a / b << "\n";
}

int main()
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
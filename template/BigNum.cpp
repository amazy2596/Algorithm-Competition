#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

#ifndef BIG_ARITHMETIC_H
#define BIG_ARITHMETIC_H

struct BigInt
{
    // 基数 B = 10^9
    static const int BASE = 1e9;
    // 基数的宽度, 用于格式化输出
    static const int WIDTH = 9;

    vector<int> s; // 存储大数的"数位"
    int sign;      // 符号: 1 为正或零, -1 为负

    // -------------------- 构造与赋值 --------------------
    BigInt() : sign(1) { s.push_back(0); }
    BigInt(long long num) { *this = num; }
    BigInt(const string& str) { *this = str; }

public:
    BigInt& operator = (long long num)
    {
        s.clear();
        sign = (num >= 0) ? 1 : -1;
        if (num < 0) num = -num;
        if (num == 0) s.push_back(0);
        while (num > 0)
        {
            s.push_back(num % BASE);
            num /= BASE;
        }
        return *this;
    }

    BigInt& operator = (const string& str)
    {
        s.clear();
        int start = 0;
        if (!str.empty() && str[0] == '-')
        {
            sign = -1;
            start = 1;
        }
        else
        {
            sign = 1;
        }

        int len = str.length() - start;
        if (len == 0) 
        {
            s.push_back(0);
            sign = 1;
            return *this;
        }

        for (int i = len; i > 0; i -= WIDTH)
        {
            int t = 0;
            int begin = max(0LL, (long long)i - WIDTH) + start;
            for (int j = begin; j < i + start; j++)
            {
                t = t * 10 + str[j] - '0';
            }
            s.push_back(t);
        }
        normalize();
        return *this;
    }

    // -------------------- 私有辅助函数 --------------------
    void normalize()
    {
        while (s.size() > 1 && s.back() == 0) s.pop_back();
        if (s.size() == 1 && s[0] == 0) sign = 1;
    }

    static int num_sign(long long n) { return (n < 0) ? -1 : 1; }

    // 高效比较 BigInt 与 long long, 不创建临时对象
    int compare_to_ll(long long num) const
    {
        if (this->sign != num_sign(num)) return this->sign > num_sign(num) ? 1 : -1;
        if (s.empty() && num == 0) return 0;
        if (s.empty()) return -1 * this->sign;
        
        vector<int> num_s;
        long long abs_num = abs(num);
        if (abs_num == 0) num_s.push_back(0);
        while(abs_num > 0) { num_s.push_back(abs_num % BASE); abs_num /= BASE; }

        if (this->s.size() != num_s.size())
            return (this->s.size() > num_s.size() ? 1 : -1) * this->sign;
        
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (this->s[i] != num_s[i])
                return (this->s[i] > num_s[i] ? 1 : -1) * this->sign;
        }
        return 0;
    }

    // -------------------- 公共辅助函数 --------------------
    long long to_long_long() const
    {
        long long res = 0;
        for (int i = s.size() - 1; i >= 0; --i) res = res * BASE + s[i];
        return res * sign;
    }

    BigInt get_abs() const
    {
        BigInt res = *this;
        res.sign = 1;
        return res;
    }
    
    string to_string() const
    {
        stringstream ss;
        ss << *this;
        return ss.str();
    }
    
    BigInt pow(int n) const
    {
        BigInt res = 1, a = *this;
        while(n > 0)
        {
            if(n & 1) res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }

    static pair<BigInt, BigInt> div_mod(const BigInt& a, const BigInt& b) 
    {
        if (b == 0) throw runtime_error("Division by zero");
        if (a.get_abs() < b.get_abs()) return {BigInt(0), a};

        BigInt q, r;
        q.sign = a.sign * b.sign;

        BigInt abs_a = a.get_abs();
        BigInt abs_b = b.get_abs();
        
        q.s.resize(abs_a.s.size());

        for (int i = abs_a.s.size() - 1; i >= 0; i--) 
        {
            r = r * BASE + abs_a.s[i];

            // Binary search for the quotient digit
            int l = 0, h = BigInt::BASE - 1, digit = 0;
            while (l <= h) 
            {
                int mid = l + (h - l) / 2;
                if (abs_b * mid <= r) 
                {
                    digit = mid;
                    l = mid + 1;
                } else
                    h = mid - 1;
            }
            q.s[i] = digit;
            r -= abs_b * digit;
        }
        q.normalize();
        r.normalize();
        if(r != 0) r.sign = a.sign; // 确保非零余数的符号正确

        return {q, r};
    }

    // -------------------- 比较运算符 --------------------
    bool operator < (const BigInt& other) const
    {
        if (sign != other.sign) return sign < other.sign;
        if (s.size() != other.s.size()) return (s.size() < other.s.size()) ^ (sign == -1);
        for (int i = s.size() - 1; i >= 0; --i)
            if (s[i] != other.s[i]) return (s[i] < other.s[i]) ^ (sign == -1);
        return false;
    }
    bool operator > (const BigInt& other) const { return other < *this; }
    bool operator <= (const BigInt& other) const { return !(*this > other); }
    bool operator >= (const BigInt& other) const { return !(*this < other); }
    bool operator == (const BigInt& other) const { return sign == other.sign && s == other.s; }
    bool operator != (const BigInt& other) const { return !(*this == other); }
    
    bool operator < (long long num) const { return compare_to_ll(num) < 0; }
    bool operator > (long long num) const { return compare_to_ll(num) > 0; }
    bool operator <= (long long num) const { return compare_to_ll(num) <= 0; }
    bool operator >= (long long num) const { return compare_to_ll(num) >= 0; }
    bool operator == (long long num) const { return compare_to_ll(num) == 0; }
    bool operator != (long long num) const { return compare_to_ll(num) != 0; }

    // -------------------- 算术: BigInt vs BigInt (成员函数) --------------------
    BigInt operator + (const BigInt& other) const;
    BigInt operator - (const BigInt& other) const;
    BigInt operator * (const BigInt& other) const;
    BigInt operator / (const BigInt& other) const;
    BigInt operator % (const BigInt& other) const;

    // -------------------- 算术: BigInt vs long long (高效成员函数) --------------------
    BigInt operator + (long long num) const { return *this + BigInt(num); }
    BigInt operator - (long long num) const { return *this - BigInt(num); }
    BigInt operator * (long long num) const;
    BigInt operator / (long long num) const;
    long long operator % (long long num) const;

    // -------------------- 复合赋值运算符 --------------------
    BigInt& operator += (const BigInt& other) { return *this = *this + other; }
    BigInt& operator -= (const BigInt& other) { return *this = *this - other; }
    BigInt& operator *= (const BigInt& other) { return *this = *this * other; }
    BigInt& operator /= (const BigInt& other) { return *this = *this / other; }
    BigInt& operator %= (const BigInt& other) { return *this = *this % other; }

    BigInt& operator += (long long num) { return *this = *this + num; }
    BigInt& operator -= (long long num) { return *this = *this - num; }
    BigInt& operator *= (long long num) { return *this = *this * num; }
    BigInt& operator /= (long long num) { return *this = *this / num; }
    // BigInt %= long long 没有意义, 因为结果是 long long

    // -------------------- 一元运算符 --------------------
    BigInt operator - () const { BigInt res = *this; if (res != 0) res.sign = -sign; return res; }

    // -------------------- 友元函数 (用于 long long op BigInt) --------------------
    friend BigInt operator + (long long a, const BigInt& b) { return b + a; }
    friend BigInt operator - (long long a, const BigInt& b) { return -(b - a); }
    friend BigInt operator * (long long a, const BigInt& b) { return b * a; }
    friend BigInt operator / (long long a, const BigInt& b) { if (b == 0) throw runtime_error("Div by 0"); return (abs(a) < b.get_abs()) ? 0 : BigInt(a / b.to_long_long()); }
    friend long long operator % (long long a, const BigInt& b) { if (b == 0) throw runtime_error("Mod by 0"); return (abs(a) < b.get_abs()) ? a : (a % b.to_long_long()); }

    friend bool operator < (long long a, const BigInt& b) { return b > a; }
    friend bool operator > (long long a, const BigInt& b) { return b < a; }
    friend bool operator <= (long long a, const BigInt& b) { return b >= a; }
    friend bool operator >= (long long a, const BigInt& b) { return b <= a; }
    friend bool operator == (long long a, const BigInt& b) { return b == a; }
    friend bool operator != (long long a, const BigInt& b) { return b != a; }
    
    friend ostream& operator << (ostream& out, const BigInt& num);
    friend istream& operator >> (istream& in, BigInt& num);
};

// -------------------- BigInt 函数实现 --------------------
BigInt BigInt::operator + (const BigInt& other) const
{
    if (sign == other.sign)
    {
        BigInt res;
        res.s.clear();
        res.sign = sign;
        long long carry = 0;
        for (size_t i = 0; i < s.size() || i < other.s.size() || carry; ++i)
        {
            if (i < s.size()) carry += s[i];
            if (i < other.s.size()) carry += other.s[i];
            res.s.push_back(carry % BASE);
            carry /= BASE;
        }
        res.normalize(); return res;
    }
    if (sign == -1) return other - (-(*this));
    return *this - (-other);
}

BigInt BigInt::operator - (const BigInt& other) const
{
    if (sign == other.sign)
    {
        if (this->get_abs() >= other.get_abs())
        {
            BigInt res;
            res.s.clear();
            res.sign = sign;
            long long borrow = 0;
            for (size_t i = 0; i < s.size(); ++i)
            {
                long long current = s[i] - borrow;
                if (i < other.s.size()) current -= other.s[i];
                if (current < 0) { current += BASE; borrow = 1; }
                else { borrow = 0; }
                res.s.push_back(current);
            }
            res.normalize(); return res;
        }
        return -(other - *this);
    }
    if (sign == -1) return -((-*this) + other);
    return *this + (-other);
}

BigInt BigInt::operator * (const BigInt& other) const
{
    BigInt res;
    res.sign = sign * other.sign;
    res.s.resize(s.size() + other.s.size());
    for (size_t i = 0; i < s.size(); ++i)
    {
        long long carry = 0;
        for (size_t j = 0; j < other.s.size() || carry > 0; ++j)
        {
            long long current = res.s[i + j] + carry;
            if (j < other.s.size()) current += (long long)s[i] * other.s[j];
            res.s[i + j] = current % BASE;
            carry = current / BASE;
        }
    }
    res.normalize(); return res;
}

BigInt BigInt::operator / (const BigInt& other) const 
{
    return div_mod(*this, other).first;
}

BigInt BigInt::operator % (const BigInt& other) const 
{
    return div_mod(*this, other).second;
}

BigInt BigInt::operator * (long long num) const
{
    if (num == 0) return 0;
    BigInt res = *this;
    res.sign *= num_sign(num);
    num = abs(num);
    
    long long carry = 0;
    for (size_t i = 0; i < res.s.size() || carry > 0; ++i)
    {
        if (i == res.s.size()) res.s.push_back(0);
        long long current = res.s[i] * num + carry;
        res.s[i] = current % BASE;
        carry = current / BASE;
    }
    res.normalize(); return res;
}

BigInt BigInt::operator / (long long num) const
{
    if (num == 0) throw runtime_error("Division by zero");
    BigInt res; res.sign = this->sign;
    if (num < 0) { res.sign *= -1; num = -num; }
    
    res.s.resize(s.size());
    long long rem = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        long long current = rem * BASE + s[i];
        res.s[i] = current / num;
        rem = current % num;
    }
    res.normalize(); return res;
}

long long BigInt::operator % (long long num) const
{
    if (num == 0) throw runtime_error("Modulo by zero");
    num = abs(num);
    long long rem = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        rem = (rem * BASE + s[i]) % num;
    }
    return rem * this->sign;
}

ostream& operator << (ostream& out, const BigInt& num)
{
    if (num.sign == -1) out << '-';
    out << (num.s.empty() ? 0 : num.s.back());
    for (int i = num.s.size() - 2; i >= 0; --i)
    {
        out << setfill('0') << setw(BigInt::WIDTH) << num.s[i];
    }
    return out;
}

istream& operator >> (istream& in, BigInt& num)
{
    string str;
    if (in >> str) num = str;
    return in;
}

inline BigInt abs(const BigInt& num)
{
    return num.get_abs();
}

#endif // BIG_ARITHMETIC_H

#ifndef BIG_DECIMAL_H
#define BIG_DECIMAL_H

struct BigDecimal
{
    // 用于控制除法运算的额外精度, 可根据需要调整
    static const int DIVISION_PRECISION = 100;

    BigInt value;     // 存储 scaled 后的整数值
    size_t precision; // 存储小数位数

    // -------------------- 构造函数 --------------------
    BigDecimal() : value(0), precision(0) {}
    BigDecimal(long long num) : value(num), precision(0) {}
    BigDecimal(const BigInt& v) : value(v), precision(0) {}
    BigDecimal(const string& str) { *this = str; }
    
public:
    // 私有构造函数, 仅在内部使用, 避免重复 normalize
    BigDecimal(const BigInt& v, size_t p) : value(v), precision(p) {}

    // -------------------- 赋值运算符 --------------------
    BigDecimal& operator = (const string& str)
    {
        string s = str;
        int s_sign = 1;
        if (!s.empty() && s[0] == '-') { s_sign = -1; s = s.substr(1); }

        size_t dot_pos = s.find('.');
        if (dot_pos == string::npos)
        {
            value = BigInt(s);
            precision = 0;
        }
        else
        {
            precision = s.length() - dot_pos - 1;
            s.erase(dot_pos, 1);
            value = BigInt(s);
        }
        value.sign = s_sign;
        normalize();
        return *this;
    }

    // -------------------- 私有辅助函数 --------------------
    void normalize()
    {
        if (value == 0) { precision = 0; return; }
        while (precision > 0 && value % 10 == 0)
        {
            value /= 10;
            precision--;
        }
    }

    // -------------------- 公共辅助函数 --------------------
    string to_string() const
    {
        string s = value.get_abs().to_string();
        string res = "";
        if (value.sign == -1) res += '-';

        if (precision == 0)
        {
            res += s;
        }
        else
        {
            if (s.length() <= precision)
            {
                res += "0.";
                res += string(precision - s.length(), '0');
                res += s;
            }
            else
            {
                res += s.substr(0, s.length() - precision) + "." + s.substr(s.length() - precision);
            }
        }
        return res;
    }

    BigDecimal get_abs() const
    {
        BigDecimal res = *this;
        // 确保非零值才修改符号，零的符号总是1
        if (res.value != 0) 
        {
            res.value.sign = 1;
        }
        return res;
    }

    // -------------------- 核心算术: BigDecimal op BigDecimal --------------------
    BigDecimal operator + (const BigDecimal& other) const
    {
        BigInt v1 = this->value;
        BigInt v2 = other.value;
        size_t target_precision = max(this->precision, other.precision);
        if (this->precision < target_precision) v1 = v1 * BigInt(10).pow(target_precision - this->precision);
        if (other.precision < target_precision) v2 = v2 * BigInt(10).pow(target_precision - other.precision);
        BigDecimal res(v1 + v2, target_precision);
        res.normalize();
        return res;
    }

    BigDecimal operator - (const BigDecimal& other) const
    {
        BigInt v1 = this->value;
        BigInt v2 = other.value;
        size_t target_precision = max(this->precision, other.precision);
        if (this->precision < target_precision) v1 = v1 * BigInt(10).pow(target_precision - this->precision);
        if (other.precision < target_precision) v2 = v2 * BigInt(10).pow(target_precision - other.precision);
        BigDecimal res(v1 - v2, target_precision);
        res.normalize();
        return res;
    }
    
    BigDecimal operator * (const BigDecimal& other) const
    {
        BigDecimal res(this->value * other.value, this->precision + other.precision);
        res.normalize();
        return res;
    }

    BigDecimal operator / (const BigDecimal& other) const
    {
        if (other.value == 0) throw runtime_error("BigDecimal division by zero");
        BigInt dividend = this->value * BigInt(10).pow(other.precision + DIVISION_PRECISION);
        BigInt new_value = dividend / other.value;
        size_t new_precision = this->precision + DIVISION_PRECISION;
        BigDecimal res(new_value, new_precision);
        res.normalize();
        return res;
    }
    
    // 注意: Modulo (%) 对小数没有明确的通用定义, 因此不予实现.
    
    // -------------------- 混合类型算术 (通过类型转换实现) --------------------
    BigDecimal operator + (const BigInt& other) const { return *this + BigDecimal(other); }
    BigDecimal operator - (const BigInt& other) const { return *this - BigDecimal(other); }
    BigDecimal operator * (const BigInt& other) const { return *this * BigDecimal(other); }
    BigDecimal operator / (const BigInt& other) const { return *this / BigDecimal(other); }
    
    BigDecimal operator + (long long other) const { return *this + BigDecimal(other); }
    BigDecimal operator - (long long other) const { return *this - BigDecimal(other); }
    BigDecimal operator * (long long other) const { return *this * BigDecimal(other); }
    BigDecimal operator / (long long other) const { return *this / BigDecimal(other); }

    // -------------------- 复合赋值运算符 (完整版) --------------------
    BigDecimal& operator += (const BigDecimal& other) { return *this = *this + other; }
    BigDecimal& operator -= (const BigDecimal& other) { return *this = *this - other; }
    BigDecimal& operator *= (const BigDecimal& other) { return *this = *this * other; }
    BigDecimal& operator /= (const BigDecimal& other) { return *this = *this / other; }
    
    BigDecimal& operator += (const BigInt& other) { return *this = *this + other; }
    BigDecimal& operator -= (const BigInt& other) { return *this = *this - other; }
    BigDecimal& operator *= (const BigInt& other) { return *this = *this * other; }
    BigDecimal& operator /= (const BigInt& other) { return *this = *this / other; }
    
    BigDecimal& operator += (long long other) { return *this = *this + other; }
    BigDecimal& operator -= (long long other) { return *this = *this - other; }
    BigDecimal& operator *= (long long other) { return *this = *this * other; }
    BigDecimal& operator /= (long long other) { return *this = *this / other; }

    // -------------------- 比较运算符 (完整版) --------------------
    bool operator < (const BigDecimal& other) const;
    bool operator > (const BigDecimal& other) const { return other < *this; }
    bool operator <= (const BigDecimal& other) const { return !(*this > other); }
    bool operator >= (const BigDecimal& other) const { return !(*this < other); }
    bool operator == (const BigDecimal& other) const;
    bool operator != (const BigDecimal& other) const { return !(*this == other); }
    
    bool operator < (const BigInt& other) const { return *this < BigDecimal(other); }
    bool operator > (const BigInt& other) const { return *this > BigDecimal(other); }
    bool operator <= (const BigInt& other) const { return *this <= BigDecimal(other); }
    bool operator >= (const BigInt& other) const { return *this >= BigDecimal(other); }
    bool operator == (const BigInt& other) const { return *this == BigDecimal(other); }
    bool operator != (const BigInt& other) const { return *this != BigDecimal(other); }

    bool operator < (long long other) const { return *this < BigDecimal(other); }
    bool operator > (long long other) const { return *this > BigDecimal(other); }
    bool operator <= (long long other) const { return *this <= BigDecimal(other); }
    bool operator >= (long long other) const { return *this >= BigDecimal(other); }
    bool operator == (long long other) const { return *this == BigDecimal(other); }
    bool operator != (long long other) const { return *this != BigDecimal(other); }

    // -------------------- 一元运算符 --------------------
    BigDecimal operator - () const { BigDecimal res = *this; res.value = -res.value; return res; }

    // -------------------- 友元函数 (用于 外部类型 op BigDecimal) --------------------
    friend BigDecimal operator + (const BigInt& a, const BigDecimal& b) { return BigDecimal(a) + b; }
    friend BigDecimal operator - (const BigInt& a, const BigDecimal& b) { return BigDecimal(a) - b; }
    friend BigDecimal operator * (const BigInt& a, const BigDecimal& b) { return BigDecimal(a) * b; }
    friend BigDecimal operator / (const BigInt& a, const BigDecimal& b) { return BigDecimal(a) / b; }

    friend BigDecimal operator + (long long a, const BigDecimal& b) { return BigDecimal(a) + b; }
    friend BigDecimal operator - (long long a, const BigDecimal& b) { return BigDecimal(a) - b; }
    friend BigDecimal operator * (long long a, const BigDecimal& b) { return BigDecimal(a) * b; }
    friend BigDecimal operator / (long long a, const BigDecimal& b) { return BigDecimal(a) / b; }
    
    friend bool operator < (const BigInt& a, const BigDecimal& b) { return BigDecimal(a) < b; }
    friend bool operator > (const BigInt& a, const BigDecimal& b) { return BigDecimal(a) > b; }
    friend bool operator <= (const BigInt& a, const BigDecimal& b) { return BigDecimal(a) <= b; }
    friend bool operator >= (const BigInt& a, const BigDecimal& b) { return BigDecimal(a) >= b; }
    friend bool operator == (const BigInt& a, const BigDecimal& b) { return BigDecimal(a) == b; }
    friend bool operator != (const BigInt& a, const BigDecimal& b) { return BigDecimal(a) != b; }
    
    friend bool operator < (long long a, const BigDecimal& b) { return BigDecimal(a) < b; }
    friend bool operator > (long long a, const BigDecimal& b) { return BigDecimal(a) > b; }
    friend bool operator <= (long long a, const BigDecimal& b) { return BigDecimal(a) <= b; }
    friend bool operator >= (long long a, const BigDecimal& b) { return BigDecimal(a) >= b; }
    friend bool operator == (long long a, const BigDecimal& b) { return BigDecimal(a) == b; }
    friend bool operator != (long long a, const BigDecimal& b) { return BigDecimal(a) != b; }
    
    friend ostream& operator << (ostream& out, const BigDecimal& num) { out << num.to_string(); return out; }
    friend istream& operator >> (istream& in, BigDecimal& num) { string s; if (in >> s) num = s; return in; }
};

// -------------------- BigDecimal 函数实现 --------------------
bool BigDecimal::operator < (const BigDecimal& other) const
{
    BigInt v1 = this->value, v2 = other.value;
    size_t p1 = this->precision, p2 = other.precision;
    size_t target_precision = max(p1, p2);
    if (p1 < target_precision) v1 = v1 * BigInt(10).pow(target_precision - p1);
    if (p2 < target_precision) v2 = v2 * BigInt(10).pow(target_precision - p2);
    return v1 < v2;
}

bool BigDecimal::operator == (const BigDecimal& other) const
{
    BigDecimal temp_a = *this; temp_a.normalize();
    BigDecimal temp_b = other; temp_b.normalize();
    return temp_a.value == temp_b.value && temp_a.precision == temp_b.precision;
}

inline BigDecimal abs(const BigDecimal& num)
{
    return num.get_abs();
}

#endif // BIG_DECIMAL_H

BigDecimal calc_arctan(int d, int precision_digits) 
{
    // 1. 放大因子：多加几位精度以防误差
    int margin = 10;
    BigInt scale_factor = BigInt(10).pow(precision_digits + margin);

    // 2. 初始项：(1/d) * scale_factor
    BigInt term = scale_factor / d;
    
    // 3. 累加和（BigInt 类型）
    BigInt total_sum = term;

    BigInt d_squared = BigInt(d) * d;

    for (long long k = 1; ; ++k) 
    {
        // 4. 高效迭代：只用整数除法
        // term_k = term_{k-1} / d^2
        term = term / d_squared;
        
        // 5. 如果项变得太小，无法影响整数部分，则停止
        if (term == 0)
            break;

        // 6. 累加或累减
        // full_term = (-1)^k * term / (2k+1)
        if (k % 2 == 1) // k=1, 3, 5... (减)
            total_sum -= term / (2 * k + 1);
        else // k=2, 4, 6... (加)
            total_sum += term / (2 * k + 1);
    }
    
    // 7. 一次性转换为 BigDecimal
    return BigDecimal(total_sum, precision_digits + margin);
}

BigDecimal get_pi(int precision)
{
    BigDecimal arctan5 = calc_arctan(5, precision);
    BigDecimal arctan239 = calc_arctan(239, precision);
    return (arctan5 * 4 - arctan239) * 4;
}

BigDecimal get_e(int precision_digits) 
{
    // 1. 放大因子，多加几位以防误差
    int margin = 10;
    BigInt scale_factor = BigInt(10).pow(precision_digits + margin);

    // 2. 初始项 T_0 = scale_factor / 0! = scale_factor
    BigInt term = scale_factor;

    // 3. 累加和，初始为 T_0
    BigInt total_sum = term;

    // 4. 从 k=1 开始迭代
    for (long long k = 1; ; ++k) 
    {
        // 4a. 高效递推: T_k = T_{k-1} / k
        term = term / k;
        
        // 4b. 终止条件: 当项小到无法影响整数和时停止
        if (term == 0)
            break;

        // 4c. 累加当前项
        total_sum += term;
    }

    // 5. 一次性转换为 BigDecimal
    return BigDecimal(total_sum, precision_digits + margin);
}

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
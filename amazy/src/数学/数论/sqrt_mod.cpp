#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

i64 fast_pow(i64 a, i64 b, i64 mod) 
{
    i64 res = 1;
    a %= mod;
    while (b) 
    {
        if (b & 1)
            res = (1LL * res * a) % mod;

        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

i64 inv(i64 x, i64 mod) 
{
    return fast_pow(x, mod - 2, mod);
}

/**
 * @brief 计算模意义下的二次剩余，即求解方程 x^2 = a (mod p)。
 *        该函数实现了 Tonelli-Shanks 算法，并包含了针对特殊情况的优化。
 * 
 * @param a 方程中的常数项 a。
 * @param mod 模数 p，要求必须是一个奇素数。
 * @return  如果方程有解，返回其中一个解 x。方程的另一个解是 mod - x。
 *          如果方程无解，返回 -1。
 *          如果 a = 0，返回 0。
 */
i64 sqrt_mod(i64 a, i64 mod) 
{
    // 将 a 化为最小正整数
    a %= mod;
    if (a < 0) a += mod;

    // ----- 特殊情况处理 -----
    // a = 0，解为 0
    if (a == 0) return 0;
    // p = 2，解为 a 本身
    if (mod == 2) return a;

    // ----- 使用欧拉判别法检查解是否存在 -----
    // (a/p) = a^((p-1)/2) mod p
    // 如果结果为 p-1 (即 -1)，则无解
    if (fast_pow(a, (mod - 1) / 2, mod) == mod - 1)
        return -1;

    // ----- p = 3 (mod 4) 的简单情况 -----
    // x = a^((p+1)/4) mod p
    if (mod % 4 == 3)
        return fast_pow(a, (mod + 1) / 4, mod);

    // ----- p = 1 (mod 4) 的 Tonelli-Shanks 算法 -----
    // 1. 将 p-1 分解为 Q * 2^S，其中 Q 是奇数
    i64 S = 0;
    i64 Q = mod - 1;
    while (Q % 2 == 0)
    {
        S++;
        Q /= 2;
    }
    // 如果 S=1, 那么 p = Q*2+1, Q为奇数, p=2Q+1, 此时 p%4=3，上面已处理
    // 所以这里的 S >= 2

    // 2. 找到一个二次非剩余 n
    i64 n = 2;
    while (fast_pow(n, (mod - 1) / 2, mod) != mod - 1) 
        n++;

    // 3. 初始化变量
    i64 M = S;
    i64 c = fast_pow(n, Q, mod); // c = n^Q mod p
    i64 t = fast_pow(a, Q, mod); // t = a^Q mod p
    i64 R = fast_pow(a, (Q + 1) / 2, mod); // R = a^((Q+1)/2) mod p

    // 4. 主循环
    while (t != 1) 
    {
        if (t == 0) return 0; // a 是 0 的情况
        
        // 找到最小的 i > 0 使得 t^(2^i) = 1 (mod p)
        i64 i = 0;
        i64 temp_t = t;
        while (temp_t != 1) 
        {
            temp_t = (i128)temp_t * temp_t % mod;
            i++;
        }
        
        // 理论上不会发生，除非输入p不是素数
        if (i >= M) return -1;

        // 计算 b = c^(2^(M-i-1))
        i64 b_exp = 1LL << (M - i - 1); // 2^(M-i-1)
        i64 b = fast_pow(c, b_exp, mod);

        // 更新 M, c, t, R
        M = i;
        c = (i128)b * b % mod;
        t = (i128)t * c % mod;
        R = (i128)R * b % mod;
    }

    return R;
}

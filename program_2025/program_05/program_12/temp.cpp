#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::hex, std::setw, std::setfill, std::uppercase
#include <sstream> // For std::stringstream
#include <utility> // For std::pair

// 类型定义，使用16位无符号整数
typedef unsigned short uint16;

// 将16位无符号整数转换为4位十六进制字符串，并添加 'H' 后缀
std::string to_hex(uint16 val) {
    std::stringstream ss;
    ss << std::hex << std::uppercase << std::setw(4) << std::setfill('0') << val;
    return ss.str() + "H";
}

// 将十六进制字符串（可选 'H' 后缀）转换为16位无符号整数
uint16 from_hex(std::string hex_str) {
    if (hex_str.empty()) {
        return 0;
    }
    if (hex_str.back() == 'H' || hex_str.back() == 'h') {
        hex_str.pop_back();
    }
    if (hex_str.empty()) {
        return 0;
    }
    unsigned long val;
    try {
        val = std::stoul(hex_str, nullptr, 16);
    } catch (const std::invalid_argument& ia) {
        return 0; 
    } catch (const std::out_of_range& oor) {
        return 0xFFFF; 
    }
    return static_cast<uint16>(val & 0xFFFF);
}

// 16位逻辑和算术运算函数
uint16 op_not(uint16 a) {
    return (~a) & 0xFFFF;
}

uint16 op_and(uint16 a, uint16 b) {
    return (a & b) & 0xFFFF;
}

uint16 op_or(uint16 a, uint16 b) {
    return (a | b) & 0xFFFF;
}

uint16 op_xor(uint16 a, uint16 b) {
    return (a ^ b) & 0xFFFF;
}

uint16 op_sum(uint16 a, uint16 b) { // 算术加
    return (static_cast<uint16>(a + b)) & 0xFFFF;
}

uint16 op_sub(uint16 a, uint16 b) { // 算术减
    return (static_cast<uint16>(a - b)) & 0xFFFF;
}

// 将整数转换为4位二进制字符串，并添加 'B' 后缀
std::string to_binary_s(int val) {
    if (val < 0 || val > 15) return "ERRB";
    std::string bin_str;
    for (int i = 3; i >= 0; --i) {
        bin_str += ((val >> i) & 1) ? '1' : '0';
    }
    return bin_str + "B";
}


// 核心计算函数 - 根据用户定义的符号规则
std::pair<std::string, std::string> calculate_f(uint16 a_val, uint16 b_val, int s_val, int m_val, int cn_val_for_m0) {
    uint16 f_val = 0;
    std::string op_description_str = "";
    std::string s_binary_display = to_binary_s(s_val);

    uint16 not_a = op_not(a_val);
    uint16 not_b = op_not(b_val);

    if (m_val == 1) { // 逻辑运算 (M=H)
        // 根据用户定义: + 是 OR, / 是 NOT, * 是 AND
        std::string op_description_base = "逻辑运算 (M=1), S=" + s_binary_display;
        if (s_val == 0)  { f_val = not_a; op_description_str = op_description_base + ": F = /A"; }
        else if (s_val == 1)  { f_val = op_not(op_or(a_val, b_val)); op_description_str = op_description_base + ": F = /(A+B)"; } // A+B is A OR B
        else if (s_val == 2)  { f_val = op_and(not_a, b_val); op_description_str = op_description_base + ": F = /A*B"; } // /A*B is (NOT A) AND B
        else if (s_val == 3)  { f_val = 0; op_description_str = op_description_base + ": F = 0"; }
        else if (s_val == 4)  { f_val = op_not(op_and(a_val, b_val)); op_description_str = op_description_base + ": F = /(A*B)"; } // A*B is A AND B
        else if (s_val == 5)  { f_val = not_b; op_description_str = op_description_base + ": F = /B"; }
        else if (s_val == 6)  { f_val = op_xor(a_val, b_val); op_description_str = op_description_base + ": F = (/A*B+A*/B) => A XOR B"; } // (/A*B + A*/B) is (NOT A AND B) OR (A AND NOT B) which is A XOR B
        else if (s_val == 7)  { f_val = op_and(a_val, not_b); op_description_str = op_description_base + ": F = A*/B"; } // A*/B is A AND (NOT B)
        else if (s_val == 8)  { f_val = op_or(not_a, b_val); op_description_str = op_description_base + ": F = /A+B"; } // /A+B is (NOT A) OR B
        else if (s_val == 9)  { f_val = op_not(op_xor(a_val, b_val)); op_description_str = op_description_base + ": F = /(/A*B+A*/B) => NOT (A XOR B)"; }
        else if (s_val == 10) { f_val = b_val; op_description_str = op_description_base + ": F = B"; }
        else if (s_val == 11) { f_val = op_and(a_val, b_val); op_description_str = op_description_base + ": F = A*B"; }
        else if (s_val == 12) { f_val = 0xFFFF; op_description_str = op_description_base + ": F = 1 (FFFFH)"; }
        else if (s_val == 13) { f_val = op_or(a_val, not_b); op_description_str = op_description_base + ": F = A+/B"; } // A+/B is A OR (NOT B)
        else if (s_val == 14) { f_val = op_or(a_val, b_val); op_description_str = op_description_base + ": F = A+B"; } // A+B is A OR B
        else if (s_val == 15) { f_val = a_val; op_description_str = op_description_base + ": F = A"; }
        else { return {"错误", "内部错误：未知的S值(逻辑)"}; }

    } else if (m_val == 0) { // 算术运算 (M=L)
        // 根据用户定义: + 是 OR, / 是 NOT, * 是 AND, '加' 是 SUM, '减' 是 SUB
        std::string op_description_base = "算术运算 (M=0), S=" + s_binary_display + ", Cn=" + std::to_string(cn_val_for_m0);
        uint16 temp_f_cn1 = 0;
        std::string op_desc_cn1_expr = "";

        if (s_val == 0)    { temp_f_cn1 = a_val; op_desc_cn1_expr = "A"; }
        else if (s_val == 1)  { temp_f_cn1 = op_or(a_val, b_val); op_desc_cn1_expr = "A+B (A OR B)"; } // F=A+B
        else if (s_val == 2)  { temp_f_cn1 = op_or(a_val, not_b); op_desc_cn1_expr = "A+/B (A OR (NOT B))"; } // F=A+/B
        else if (s_val == 3)  { temp_f_cn1 = 0xFFFF; op_desc_cn1_expr = "-1 (FFFFH)"; } // F=-1
        else if (s_val == 4)  { temp_f_cn1 = op_sum(a_val, op_and(a_val, not_b)); op_desc_cn1_expr = "A 加 A*/B (A SUM (A AND (NOT B)))"; } // F=A 加 A*/B
        else if (s_val == 5)  { temp_f_cn1 = op_sum(op_or(a_val, b_val), op_and(a_val, not_b)); op_desc_cn1_expr = "(A+B) 加 A*/B ((A OR B) SUM (A AND (NOT B)))"; } // F=(A+B) 加 A*/B
        else if (s_val == 6)  { temp_f_cn1 = op_sub(op_sub(a_val, b_val), 1); op_desc_cn1_expr = "A 减 B 减 1"; }
        else if (s_val == 7)  { temp_f_cn1 = op_sub(op_and(a_val, not_b), 1); op_desc_cn1_expr = "A*/B 减 1 ((A AND (NOT B)) SUB 1)"; } // F=A*/B 减 1
        else if (s_val == 8)  { temp_f_cn1 = op_sum(a_val, op_and(a_val, b_val)); op_desc_cn1_expr = "A 加 A*B (A SUM (A AND B))"; } // F=A 加 A*B
        else if (s_val == 9)  { temp_f_cn1 = op_sum(a_val, b_val); op_desc_cn1_expr = "A 加 B (A SUM B)"; } // F=A 加 B
        else if (s_val == 10) { temp_f_cn1 = op_sum(op_or(a_val, not_b), op_and(a_val, b_val)); op_desc_cn1_expr = "(A+/B) 加 A*B ((A OR (NOT B)) SUM (A AND B))"; } // F=(A+/B) 加 A*B
        else if (s_val == 11) { temp_f_cn1 = op_sub(op_and(a_val, b_val), 1); op_desc_cn1_expr = "A*B 减 1 ((A AND B) SUB 1)"; } // F=A*B 减 1
        else if (s_val == 12) { temp_f_cn1 = op_sum(a_val, a_val); op_desc_cn1_expr = "A 加 A (A SUM A)"; } // F=A 加 A
        else if (s_val == 13) { temp_f_cn1 = op_sum(op_or(a_val, b_val), a_val); op_desc_cn1_expr = "(A+B) 加 A ((A OR B) SUM A)"; } // F=(A+B) 加 A
        else if (s_val == 14) { temp_f_cn1 = op_sum(op_or(a_val, not_b), a_val); op_desc_cn1_expr = "(A+/B) 加 A ((A OR (NOT B)) SUM A)"; } // F=(A+/B) 加 A
        else if (s_val == 15) { temp_f_cn1 = op_sub(a_val, 1); op_desc_cn1_expr = "A 减 1"; }
        else { return {"错误", "内部错误：未知的S值(算术)"}; }

        std::string op_desc_cn1_full = "F = " + op_desc_cn1_expr;

        if (cn_val_for_m0 == 1) { // 无进位 (Cn=1)
            f_val = temp_f_cn1;
            op_description_str = op_description_base + " (无进位): " + op_desc_cn1_full;
        } else if (cn_val_for_m0 == 0) { // 有进位 (Cn=0)
            // 对于有进位，通常是在无进位的基础上“加1” (算术加1)
            // 但需要根据功能表的具体描述来确定，如 "F=A 加 1", "F=(A+B) 加 1"
            if (s_val == 0) { f_val = op_sum(a_val, 1); op_description_str = op_description_base + " (有进位): F = A 加 1"; }
            else if (s_val == 1) { f_val = op_sum(op_or(a_val, b_val), 1); op_description_str = op_description_base + " (有进位): F = (A+B) 加 1 ((A OR B) SUM 1)";}
            else if (s_val == 2) { f_val = op_sum(op_or(a_val, not_b), 1); op_description_str = op_description_base + " (有进位): F = (A+/B) 加 1 ((A OR (NOT B)) SUM 1)";}
            else if (s_val == 3) { f_val = 0; op_description_str = op_description_base + " (有进位): F = 0"; } // F=0
            else if (s_val == 4) { f_val = op_sum(op_sum(a_val, op_and(a_val, not_b)), 1); op_description_str = op_description_base + " (有进位): F = A 加 A*/B 加 1"; }
            else if (s_val == 5) { f_val = op_sum(op_sum(op_or(a_val, b_val), op_and(a_val, not_b)), 1); op_description_str = op_description_base + " (有进位): F = (A+B) 加 A*/B 加 1"; }
            else if (s_val == 6) { f_val = op_sub(a_val, b_val); op_description_str = op_description_base + " (有进位): F = A 减 B"; } // F=A 减 B
            else if (s_val == 7) { f_val = op_and(a_val, not_b); op_description_str = op_description_base + " (有进位): F = A*/B (A AND (NOT B))"; } // F=A*/B
            else if (s_val == 8) { f_val = op_sum(op_sum(a_val, op_and(a_val, b_val)), 1); op_description_str = op_description_base + " (有进位): F = A 加 A*B 加 1"; }
            else if (s_val == 9) { f_val = op_sum(op_sum(a_val, b_val), 1); op_description_str = op_description_base + " (有进位): F = A 加 B 加 1"; }
            else if (s_val == 10){ f_val = op_sum(op_sum(op_or(a_val, not_b), op_and(a_val, b_val)), 1); op_description_str = op_description_base + " (有进位): F = (A+/B) 加 A*B 加 1"; } // 表中是 (A+B) 加 A*B 加 1, 但S=10的Cn=1是(A+/B)加A*B, 假设这里也应是(A+/B)
            else if (s_val == 11){ f_val = op_and(a_val, b_val); op_description_str = op_description_base + " (有进位): F = A*B (A AND B)"; } // F=A*B
            else if (s_val == 12){ f_val = op_sum(op_sum(a_val, a_val), 1); op_description_str = op_description_base + " (有进位): F = A 加 A 加 1"; }
            else if (s_val == 13){ f_val = op_sum(op_sum(op_or(a_val, b_val), a_val), 1); op_description_str = op_description_base + " (有进位): F = (A+B) 加 A 加 1"; }
            else if (s_val == 14){ f_val = op_sum(op_sum(op_or(a_val, not_b), a_val), 1); op_description_str = op_description_base + " (有进位): F = (A+/B) 加 A 加 1"; }
            else if (s_val == 15){ f_val = a_val; op_description_str = op_description_base + " (有进位): F = A"; } // F=A
            else { return {"错误", "内部错误：未知的S值(算术, Cn=0)"}; }
        } else { return {"错误", "无效的Cn值 (必须是0或1)"}; }
    } else { return {"错误", "无效的M值 (必须是0或1)"}; }

    return {to_hex(f_val), op_description_str};
}


int main() {
    std::cout << "74LS181 ALU 模拟器 - 自动计算 (根据用户定义符号规则) - C++ 版本" << std::endl;
    std::cout << std::string(80, '=') << std::endl;

    struct TestCase {
        std::string label;
        std::string a_hex;
        std::string b_hex;
        std::vector<int> s_values;
    };

    // 使用您图片中的 A 和 B 值
    std::vector<TestCase> test_cases = {
        {"计算组 (A=1234H, B=5678H - 参照用户图片和符号定义)", "1234H", "5678H", {}},
    };
    for (int i = 0; i <= 15; ++i) { // 填充 S 值从 0 到 15
        test_cases[0].s_values.push_back(i);
    }

    for (const auto& test_case : test_cases) {
        // std::cout << "\n--- " << test_case.label << " ---" << std::endl;
        uint16 a_val = from_hex(test_case.a_hex);
        uint16 b_val = from_hex(test_case.b_hex);
        std::cout << "使用 A = " << to_hex(a_val) << ", B = " << to_hex(b_val) << std::endl;
        // std::cout << std::string(test_case.label.length() + 8, '-') << std::endl;

        std::cout << std::left << std::setw(12) << "S3S2S1S0" << " | "
                  << std::setw(12) << "M=0, Cn=1 (无进位)" << " | "
                  << std::setw(12) << "M=0, Cn=0 (有进位)" << " | "
                  << std::setw(12) << "M=1 (逻辑运算)" << std::endl;
        // std::cout << std::string(12, '-') << " | "
                //   << std::string(85, '-') << " | "
                //   << std::string(85, '-') << " | "
                //   << std::string(70, '-') << std::endl;

        for (int s_decimal : test_case.s_values) {
            std::string s_binary_display = to_binary_s(s_decimal);

            auto result_m0_cn1 = calculate_f(a_val, b_val, s_decimal, 0, 1);
            auto result_m0_cn0 = calculate_f(a_val, b_val, s_decimal, 0, 0);
            auto result_m1     = calculate_f(a_val, b_val, s_decimal, 1, 1); 

            std::string desc_m0_cn1_clean = result_m0_cn1.second;
            size_t pos_m0_cn1 = desc_m0_cn1_clean.find("): ");
            if (pos_m0_cn1 != std::string::npos) desc_m0_cn1_clean = desc_m0_cn1_clean.substr(pos_m0_cn1 + 3);
            else { pos_m0_cn1 = desc_m0_cn1_clean.find(": "); if (pos_m0_cn1 != std::string::npos) desc_m0_cn1_clean = desc_m0_cn1_clean.substr(pos_m0_cn1 + 2); }

            std::string desc_m0_cn0_clean = result_m0_cn0.second;
            size_t pos_m0_cn0 = desc_m0_cn0_clean.find("): ");
             if (pos_m0_cn0 != std::string::npos) desc_m0_cn0_clean = desc_m0_cn0_clean.substr(pos_m0_cn0 + 3);
            else { pos_m0_cn0 = desc_m0_cn0_clean.find(": "); if (pos_m0_cn0 != std::string::npos) desc_m0_cn0_clean = desc_m0_cn0_clean.substr(pos_m0_cn0 + 2); }

            std::string desc_m1_clean = result_m1.second;
            size_t pos_m1 = desc_m1_clean.find(": ");
            if (pos_m1 != std::string::npos) desc_m1_clean = desc_m1_clean.substr(pos_m1 + 2);

            std::cout << std::left << std::setw(12) << s_binary_display << " | "
                      << std::setw(12) << (result_m0_cn1.first) << " | "
                      << std::setw(12) << (result_m0_cn0.first) << " | "
                      << std::setw(12) << (result_m1.first) << std::endl << std::endl;
        }
    }

    std::cout << "\n" << std::string(80, '=') << std::endl;
    std::cout << "所有计算完成。" << std::endl;

    return 0;
}


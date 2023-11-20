#include <iostream>

int divide(int dividend, int divisor)
{
    // 处理除数为0的情况
    if (divisor == 0) {
        std::cout << "Error: Division by zero!" << std::endl;
        return 0;
    }

    // 判断结果的符号
    int sign = (dividend < 0 ^ divisor < 0) ? -1 : 1;

    // 将被除数和除数都转换为正数
    long long absDividend = abs(dividend);
    long long absDivisor = abs(divisor);

    // 执行除法运算
    long long quotient = 0;
    while (absDividend >= absDivisor) {
        absDividend -= absDivisor;
        quotient++;
    }

    return sign < 0 ? -quotient : quotient;
}

int main()
{
    int dividend, divisor;
    std::cout << "Enter dividend: ";
    std::cin >> dividend;
    std::cout << "Enter divisor: ";
    std::cin >> divisor;

    int result = divide(dividend, divisor);
    std::cout << "Result: " << result << std::endl;

    return 0;
}

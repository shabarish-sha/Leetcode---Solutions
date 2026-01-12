#include <limits.h>

int divide(int dividend, int divisor) {
    if (divisor == 0)
        return INT_MAX;

    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long long a = dividend;
    long long b = divisor;

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    long long res = 0;

    while (a >= b) {
        long long temp = b;
        long long multiple = 1;

        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        a -= temp;
        res += multiple;
    }

    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        res = -res;

    if (res > INT_MAX) return INT_MAX;
    if (res < INT_MIN) return INT_MIN;

    return (int)res;
}

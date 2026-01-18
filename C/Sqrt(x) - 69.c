int mySqrt(int x) {
    long l = 0, r = x;
    while (l <= r) {
        long m = (l + r) / 2;
        if (m*m <= x && (m+1)*(m+1) > x)
            return m;
        if (m*m < x) l = m + 1;
        else r = m - 1;
    }
    return 0;
}

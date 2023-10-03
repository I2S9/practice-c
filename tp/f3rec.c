int f3(int n) {
    int r ;
    if (n == 0)
        return 0;
    r = f3(n - 1);
    r = r + n;
    return r;
}

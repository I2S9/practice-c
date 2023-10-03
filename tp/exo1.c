double f3iter(unsigned int n) {
    double r[n + 1];
    int i;
    r[0] = 0;
    for (i = 1; i <= n; i = i + 1) {
        r[i] = r[i - 1] + i;
    }
    return r[n];
}

int main{
  f3iter(3);
}

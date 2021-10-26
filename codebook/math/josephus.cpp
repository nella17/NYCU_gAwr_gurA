int calc(int n, int m) {
    int id = 0;
    for(int i = 2; i <= n; i++)
        id = (id+m) % i;
    return id;
}

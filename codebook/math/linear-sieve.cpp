bool *isnP;
vector<int> prime{};
void build(int n) {
    isnP = new bool[n+1]();
    isnP[0] = isnP[1] = 1;
    for(int i = 2; i <= n; i++) {
        if (!isnP[i]) prime.emplace_back(i);
        for(int p: prime) {
            if (i*p > n) break;
            isnP[i*p] = 1;
            if (i%p == 0) break;
        }
    }
}

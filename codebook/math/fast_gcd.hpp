ll fast_gcd(ll x, ll y) {
    ll g = 1;
    while (x && y) {
        const int c = __builtin_ctzll(x | y);
        g <<= c; x >>= c; y >>= c;
        x >>= __builtin_ctzll(x);
        y >>= __builtin_ctzll(y);
        if (x < y) swap(x, y);
        x -= y;
    }
    return g * (x + y);
}

ll f(ll x, ll m) { return ll((LL(x) * x + 1) % m); }
ll pollard_rho(ll n) {
    if (!(n & 1)) return 2;
    for(;;) {
        ll y = 2, x = 1 + randint(n-1), res = 1;
        for(ll sz = 2; res == 1; sz *= 2) {
            for(ll i = 0; i < sz and res <= 1; i++) {
                x = f(x, n);
                res = __gcd(abs(x - y), n);
            }
            y = x;
        }
        if (res != 0 and res != n) return res;
    }
}

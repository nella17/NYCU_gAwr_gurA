// n < 4,759,123,141      3 : 2, 7, 61
// n < 1,122,004,669,633  4 : 2, 13, 23, 1662803
// n < 3,474,749,660,383  6 : pirmes <= 13
// n < 2^64             7 :
// 2, 325, 9375, 28178, 450775, 9780504, 1795265022
bool is_prime(ll n) { // ll tns[]
    if (n < 2 or n%2 == 0) return n == 2;
    int s = __builtin_ctzll(n-1);
    for(auto a: tns) {
        auto x = fpow(a, n >> s, n);
        int i = 0;
        while (i < s and (x+1)%n > 2)
            x = ll(LL(x) * x % n), i++;
        if (i and x != n-1) return false;
    }
    return true;
}

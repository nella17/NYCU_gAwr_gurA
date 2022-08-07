/* py: from fractions import Decimal, Fraction */
struct fraction {
  ll n, d;
  fraction(ll _n = 0, ll _d = 1): n(_n), d(_d) {
    ll g = __gcd(n,d);
    n /= g; d /= g;
    if(d < 0) n *= -1, d *= -1; }
  fraction operator-() { return fraction(-n,d); }
  fraction operator+(fraction &b) {
    return fraction(n*b.d+b.n*d, d*b.d); }
  fraction operator-(fraction &b){
    return fraction(n*b.d-b.n*d, d*b.d); }
  fraction operator*(fraction &b) {
    return fraction(n*b.n, d*b.d); }
  fraction operator/(fraction &b) {
    return fraction(n*b.d, d*b.n); }
};

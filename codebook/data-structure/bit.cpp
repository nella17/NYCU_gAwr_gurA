template<typename S>
struct BIT {
#define lb(x) (x&-x)
    int sz; vector<S> ary;
    BIT(int _sz): sz(_sz), ary(_sz+1) {}
    void update(int x, S v) {
        for(x++; x <= sz; x += lb(x))
            ary[x] += v;
    }
    S query(int x) {
        S r;
        for(x++; x; x -= lb(x))
            r += ary[x];
        return r;
    }
#undef lb
};
struct S {
    int v;
    S(int _v = 0): v(_v) {}
    void operator+=(S o) { v += o.v; }
};

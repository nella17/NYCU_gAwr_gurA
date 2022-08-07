template<typename T = int, typename CMP = greater<T>>
struct SparseTable {
  int n;
  T st[__lg(MAXN) + 1][MAXN];
  CMP cmp;
  inline T max(T a, T b) { return cmp(a,b) ? a : b; }
  void init(int _n, auto data) {
    n = _n;
    for (int i = 0; i < n; ++i) st[0][i] = data[i];
    for (int i = 1, t = 2; t < n; t <<= 1, i++)
      for (int j = 0; j + t <= n; j++)
        st[i][j] = max(st[i-1][j], st[i-1][j + t/2]);
  }
  T query(int a, int b) { // [a,b]
    int t = __lg(b - a + 1);
    return max(st[t][a], st[t][b - (1 << t) + 1]);
  }
};

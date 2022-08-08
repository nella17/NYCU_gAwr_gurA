struct SAT { // 0-base
  int low[MAXN], dfn[MAXN], bln[MAXN], n, Time, nScc;
  bool instack[MAXN], istrue[MAXN];
  stack<int> st;
  vector<int> G[MAXN], SCC[MAXN];
  void init(int _n) {
    n = _n; // assert(n * 2 <= MAXN);
    for (int i = 0; i < n*2; ++i) G[i].clear();
  }
  void add_edge(int a, int b) { G[a].eb(b); }
  int rv(int a) { return a >= n ? a - n : a + n; }
  void add_clause(int a, int b) {
    add_edge(rv(a), b), add_edge(rv(b), a); }
  void dfs(int u) {
    dfn[u] = low[u] = ++Time;
    instack[u] = 1, st.push(u);
    for (int i : G[u])
      if (!dfn[i])
        dfs(i), low[u] = min(low[i], low[u]);
      else if (instack[i] and dfn[i] < dfn[u])
        low[u] = min(low[u], dfn[i]);
    if (low[u] == dfn[u]) {
      for (int x = -1; x != u;)
        x = st.top(), st.pop(),
        instack[x] = 0, bln[x] = nScc;
      ++nScc;
    }
  }
  bool solve() {
    Time = nScc = 0;
    for (int i = 0; i < n*2; ++i)
      SCC[i].clear(), low[i] = dfn[i] = bln[i] = 0;
    for (int i = 0; i < n*2; ++i)
      if (!dfn[i]) dfs(i);
    for (int i = 0; i < n*2; ++i) SCC[bln[i]].eb(i);
    for (int i = 0; i < n; ++i) {
      if (bln[i] == bln[i+n]) return false;
      istrue[i] = bln[i] < bln[i+n];
      istrue[i+n] = !istrue[i];
    }
    return true;
  }
};

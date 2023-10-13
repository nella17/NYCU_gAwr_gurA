template<int MAXV, typename T = int, T INF = INT_MAX>
struct BoundedFlow { // 0-base
  struct edge {
    int to; size_t rev; T cap, flow;
  };
  vector<edge> G[MAXV];
  int n, s, t, dis[MAXV]; size_t cur[MAXV];T cnt[MAXV];
  void init(int _n) {
    n = _n;
    for (int i = 0; i < n + 2; ++i)
      G[i].clear(), cnt[i] = 0;
  }
  void add_edge(int u, int v, T lcap, T rcap) {
    cnt[u] -= lcap, cnt[v] += lcap;
    G[u].eb(edge{ v, G[v].size(), rcap, lcap });
    G[v].eb(edge{ u, G[u].size()-1, 0, 0 });
  }
  void add_edge(int u, int v, T cap) {
    add_edge(u, v, 0, cap); }
  T dfs(int u, T cap) {
    if (u == t or !cap) return cap;
    for (auto &i = cur[u]; i < G[u].size(); i++) {
      edge &e = G[u][i];
      if (dis[e.to] == dis[u]+1 and e.cap != e.flow) {
        T df = dfs(e.to, min(e.cap - e.flow, cap));
        if (df) {
          e.flow += df, G[e.to][e.rev].flow -= df;
          return df;
        }
      }
    }
    dis[u] = -1;
    return 0;
  }
  bool bfs() {
    fill_n(dis, n + 3, -1);
    queue<int> q;
    q.push(s), dis[s] = 0;
    while (q.size()) {
      int u = q.front(); q.pop();
      for (auto &e : G[u])
        if (dis[e.to] == -1 and e.flow != e.cap)
          q.push(e.to), dis[e.to] = dis[u] + 1;
    }
    return dis[t] != -1;
  }
  T maxflow(int _s, int _t) {
    s = _s, t = _t;
    T flow = 0, df;
    while (bfs()) {
      fill_n(cur, n + 3, 0);
      while ((df = dfs(s, INF))) flow += df;
    }
    return flow;
  }
  bool solve() {
    T sum = 0;
    for (int i = 0; i < n; ++i)
      if (cnt[i] > 0)
        add_edge(n + 1, i, cnt[i]), sum += cnt[i];
      else if (cnt[i] < 0) add_edge(i, n + 2, -cnt[i]);
    if (sum != maxflow(n + 1, n + 2)) sum = -1;
    for (int i = 0; i < n; ++i)
      if (cnt[i] > 0)
        G[n + 1].pop_back(), G[i].pop_back();
      else if (cnt[i] < 0)
        G[i].pop_back(), G[n + 2].pop_back();
    return sum != -1;
  }
  T solve(int _s, int _t) {
    add_edge(_t, _s, INF);
    if (!solve()) return -1; // invalid flow
    T x = G[_t].back().flow;
    return G[_t].pop_back(), G[_s].pop_back(), x;
  }
};

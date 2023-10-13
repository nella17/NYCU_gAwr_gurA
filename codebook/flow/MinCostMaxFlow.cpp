template<int MAXV, typename T = ll, T INF = LLONG_MAX>
struct MCMF { // 0-base
  struct edge {
    int from, to, rev;
    T cap, flow, cost;
  } * past[MAXV];
  vector<edge> G[MAXV];
  bitset<MAXV> inq;
  int s, t, n;
  T mx, flow, cost, dis[MAXV], up[MAXV];
  bool BellmanFord() {
    fill_n(dis, n, INF);
    queue<int> q;
    q.push(s), inq.reset(), inq[s] = 1;
    up[s] = mx - flow, past[s] = 0, dis[s] = 0;
    while (!q.empty()) {
      int u = q.front(); q.pop(), inq[u] = 0;
      if (!up[u]) continue;
      for (auto &e : G[u])
        if (e.flow != e.cap and
          dis[e.to] > dis[u] + e.cost) {
          dis[e.to] = dis[u] + e.cost, past[e.to] = &e;
          up[e.to] = min(up[u], e.cap - e.flow);
          if (!inq[e.to]) inq[e.to] = 1, q.push(e.to);
        }
    }
    if (dis[t] == INF) return 0;
    flow += up[t], cost += up[t] * dis[t];
    for (int i = t; past[i]; i = past[i]->from) {
      auto &e = *past[i];
      e.flow += up[t], G[e.to][e.rev].flow -= up[t];
    }
    return 1;
  }
  auto solve(int _s, int _t) {
    s = _s, t = _t, cost = 0, flow = 0;
    while (BellmanFord()) ;
    return pair{ flow, cost };
  }
  void init(int _n, T _mx = INF) {
    n = _n, mx = _mx;
    for (int i = 0; i < n; ++i) G[i].clear();
  }
  void add_edge(int a, int b, T cap, T c) {
    G[a].eb(edge{ a, b, G[b].size(), cap, 0, c });
    G[b].eb(edge{ b, a, G[a].size()-1, 0, 0, -c });
  }
};

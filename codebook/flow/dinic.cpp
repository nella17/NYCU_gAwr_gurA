template<int MAXV, typename T = int, T INF = INT_MAX>
struct Dinic { // 0-base
  struct edge {
    int to; size_t rev; T cap, flow;
  };
  vector<edge> G[MAXV];
  int n, s, t, dis[MAXV]; size_t cur[MAXV];
  void init(int _n) {
    n = _n;
    for (int i = 0; i < n; i++) G[i].clear();
  }
  void reset() {
    for (int i = 0; i < n; i++)
      for (auto &j : G[i]) j.flow = 0;
  }
  void add_edge(int u, int v, T cap) {
    G[u].eb(edge{ v, G[v].size(), cap, 0 });
    G[v].eb(edge{ u, G[u].size()-1, 0, 0 });
  }
  T dfs(int u, T cap) {
    if (u == t or !cap) return cap;
    for (auto &i = cur[u]; i < G[u].size(); i++) {
      edge &e = G[u][i];
      if (dis[e.to] == dis[u]+1 and e.flow != e.cap) {
        T df = dfs(e.to, min(e.cap - e.flow, cap));
        if (df) {
          e.flow += df;
          G[e.to][e.rev].flow -= df;
          return df;
        }
      }
    }
    dis[u] = -1;
    return 0;
  }
  bool bfs() {
    fill_n(dis, n, -1);
    queue<int> q;
    q.push(s), dis[s] = 0;
    while (q.size()) {
      int x = q.front(); q.pop();
      for (auto &u : G[x])
        if (dis[u.to] == -1 and u.flow != u.cap)
          q.push(u.to), dis[u.to] = dis[x] + 1;
    }
    return dis[t] != -1;
  }
  T maxflow(int _s, int _t) {
    s = _s, t = _t;
    T flow = 0, df;
    while (bfs()) {
      fill_n(cur, n, -1);
      while ((df = dfs(s, INF))) flow += df;
    }
    return flow;
  }
};

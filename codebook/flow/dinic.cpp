struct MaxFlow { // 0-base
  struct edge {
    int to, cap, flow, rev;
  };
  vector<edge> G[MAXN];
  int s, t, dis[MAXN], cur[MAXN], n;
  int dfs(int u, int cap) {
    if (u == t or !cap) return cap;
    for (int &i = cur[u]; i < (int)G[u].size(); i++) {
      edge &e = G[u][i];
      if (dis[e.to] == dis[u]+1 and e.flow != e.cap) {
        int df = dfs(e.to, min(e.cap - e.flow, cap));
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
    memset(dis, -1, sizeof(dis));
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
  int maxflow(int _s, int _t) {
    s = _s, t = _t;
    int flow = 0, df;
    while (bfs()) {
      memset(cur, 0, sizeof(cur));
      while (df = dfs(s, INF)) flow += df;
    }
    return flow;
  }
  void init(int _n) {
    n = _n;
    for (int i = 0; i < n; i++) G[i].clear();
  }
  void reset() {
    for (int i = 0; i < n; i++)
      for (auto &j : G[i]) j.flow = 0;
  }
  void add_edge(int u, int v, int cap) {
    G[u].eb(edge{ v, cap, 0, (int)G[v].size() });
    G[v].eb(edge{ u, 0, 0, (int)G[u].size()-1 });
  }
};

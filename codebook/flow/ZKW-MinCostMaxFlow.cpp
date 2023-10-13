template<int MAXV, typename T = int, T INF = INT_MAX>
struct ZKW_MCMF {
  struct Edge {
    int u, v, nxt; T cap, cost;
  } edge[MAXV * MAXV];
  int add, head[MAXV];
  int cur[MAXV]; T dis[MAXV];
  bitset<MAXV> vis;
  int s, t, n;
  T min_cost, max_flow;
  void init(int _n) {
    n = _n, add = 0;
    fill_n(head, n, -1);
  }
  void add_edge(int u, int v, T cp, T ct) {
    edge[add] = Edge{ u, v, head[u], cp, ct };
    head[u] = add++;
    edge[add] = Edge{ v, u, head[v], 0, -ct };
    head[v] = add++;
  }
  T aug(int u, T flow) {
    if (u == t) return flow;
    vis[u] = true;
    for (int &i = cur[u]; i != -1; i = edge[i].nxt) {
      int v = edge[i].v;
      if (edge[i].cap and !vis[v] and
          dis[u] == dis[v] + edge[i].cost) {
        T tmp = aug(v, min(flow, edge[i].cap));
        edge[i].cap -= tmp;
        edge[i ^ 1].cap += tmp;
        if (tmp) return tmp;
      }
    }
    return 0;
  }
  bool modify_label() {
    T d = INF;
    for (int u = 0; u < n; u++) if (vis[u])
      for (int i = head[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].v;
        if (edge[i].cap and !vis[v])
          d = min(d, dis[v] + edge[i].cost - dis[u]);
      }
    if (d == INF) return false;
    for (int i = 0; i < n; ++i) if (vis[i]) {
      vis[i] = false;
      dis[i] += d;
    }
    return true;
  }
  auto solve(int _s, int _t) {
    s = _s, t = _t;
    min_cost = max_flow = 0;
    fill_n(dis, n, 0);
    while (true) {
      copy_n(head, n, cur);
      while (true) {
        vis.reset();
        T tmp = aug(s, INF);
        if (tmp == 0) break;
        max_flow += tmp;
        min_cost += tmp * dis[s];
      }
      if (!modify_label()) break;
    }
    return pair{ min_cost, max_flow };
  }
};

int lgN = __lg(n)+1; // dfs: dep[i], pars[i][0]
vector<vector<int>> pars(n,vector<int>(lgN));
for(int d = 1; d < lgN; d++) // pars[0][0] = 0
    for(int i = 0; i < n; i++)
        pars[i][d] = pars[pars[i][d-1]][d-1];
auto gopar = [&](int x, int w) {
    for (int d = lgN-1; d >= 0; d--)
        if (w >= (1<<d)) x = pars[x][d], w -= (1<<d);
    return x; };
auto lca = [&](int u, int v) {
    if (dep[u] < dep[v]) swap(u,v);
    u = gopar(u, dep[u] - dep[v]);
    if (u == v) return u;
    for(int d = lgN-1; d >= 0; d--)
        if (pars[u][d] != pars[v][d])
            u = pars[u][d], v = pars[v][d];
    return pars[u][0]; };

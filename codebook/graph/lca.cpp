int lgN = __lg(n)+1;
vector<vector<int>> lca_table(n,vector<int>(lgN));
{
    auto &v = lca_table;
    for(int i = 0; i < n; i++)
        v[i][0] = par[i];
    for(int d = 1; d < lgN; d++)
        for(int i = 0; i < n; i++)
            v[i][d] = v[v[i][d-1]][d-1];
}
auto lca = [&](int u, int v) {
    if (dep[u] < dep[v]) swap(u,v);
    for(int d = lgN-1; d >= 0; d--)
        if (dep[u]-d > dep[v])
            u = lca_table[u][d];
    for(int d = lgN-1; d >= 0; d--)
        if (lca_table[u][d] != lca_table[v][d])
            u = lca_table[u][d], v = lca_table[v][d];
    if (u != v) u = par[u];
    return u;
};

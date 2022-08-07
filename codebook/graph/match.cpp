array<int,SZ> mp;
array<bool,SZ> vis;
bool dfs(int now) {
    if(vis[now]) return false;
    vis[now] = true;
    for(int i = 0 ; i < n ; ++i) {
        if(!g[now][i]) continue;
        if(mp[i] == -1 or dfs(mp[i]))
            return mp[i] = now , 1;
    }
    return false;
}
int solve() {
    mp.fill(-1);
    int ret = 0 ;
    for(int i = 0 ; i < n ; ++i) {
        vis.fill(false);
        if(dfs(i)) ++ret;
    }
    return ret;
}

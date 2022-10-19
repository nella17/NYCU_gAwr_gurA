array<int,SZ> mp;
array<bool,SZ> vis;
bool dfs(int now) {
    if(vis[now]) return false;
    vis[now] = true;
    for(int i = 0; i < n; i++) {
        if(!G[now][i]) continue;
        if(mp[i] == -1 or dfs(mp[i]))
            return mp[i] = now , true;
    }
    return false;
}
int solve() {
    mp.fill(-1);
    int r = 0;
    for(int i = 0; i < n; i++) {
        vis.fill(false);
        if(dfs(i)) r++;
    }
    return r;
}

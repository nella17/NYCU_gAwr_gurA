struct Query { // BLOCK = N^{2/3}
  int id, L, R, Li, Ri, T;
  Query(int i, int l, int r, int t):
    id(i), L(l), R(r), Li(l/BLOCK), Ri(r/BLOCK), T(t){}
  bool operator<(const Query &b) const {
    return tuple{ Li,Ri,T } < tuple{ b.Li,b.Ri,b.T }; }
};
vector<Query> query;
int cur_ans, arr[MAXN], ans[MAXQ];
void solve() {
  sort(ALL(query));
  int L = 0, R = -1, T = -1;
  for(auto q: query) {
    while(T < q.T) addTime(L,R,++T); // TODO
    while(T > q.T) subTime(L,R,T--); // TODO
    while(R < q.R) add(arr[++R]); // TODO
    while(L > q.L) add(arr[--L]); // TODO
    while(R > q.R) sub(arr[R--]); // TODO
    while(L < q.L) sub(arr[L++]); // TODO
    ans[q.id] = cur_ans;
  }
}

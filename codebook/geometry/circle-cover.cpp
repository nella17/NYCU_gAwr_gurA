const int N = 1021;
struct CircleCover {
  int C;
  Cir c[N];
  bool g[N][N], overlap[N][N];
  // Area[i] : area covered by at least i circles
  Dt Area[ N ];
  void init(int _C){ C = _C; }
  struct Teve {
    Pt p; Dt ang; int add;
    Teve() {}
    Teve(Pt _a, Dt _b, int _c): p(_a),ang(_b),add(_c){}
    bool operator<(const Teve &a) const
        { return ang < a.ang; }
  } eve[N * 2];
  // strict: x = 0, otherwise x = -1
  bool disjuct(Cir &a, Cir &b, int x)
      { return sign(abs(a.O - b.O) - a.R - b.R) > x; }
  bool contain(Cir &a, Cir &b, int x)
      { return sign(a.R - b.R - abs(a.O - b.O)) > x; }
  bool contain(int i, int j) {
    /* c[j] is non-strictly in c[i]. */
    auto sij = sign(c[i].R - c[j].R);
    return (sij > 0 or (sij == 0 and i < j))
        and contain(c[i], c[j], -1);
  }
  void solve(){
    fill_n(Area, C + 2, 0);
    for(int i = 0; i < C; ++i)
      for(int j = 0; j < C; ++j)
        overlap[i][j] = contain(i, j);
    for(int i = 0; i < C; ++i)
      for(int j = 0; j < C; ++j)
        g[i][j] = !(overlap[i][j] or overlap[j][i] or
            disjuct(c[i], c[j], -1));
    for(int i = 0; i < C; ++i){
      int E = 0, cnt = 1;
      for(int j = 0; j < C; ++j)
        if(j != i and overlap[j][i])
          ++cnt;
      for(int j = 0; j < C; ++j)
        if(i != j and g[i][j]) {
          Pt aa, bb;
          CCinter(c[i], c[j], aa, bb);
    Dt A = atan2(aa.sd - c[i].O.sd, aa.ft - c[i].O.ft);
    Dt B = atan2(bb.sd - c[i].O.sd, bb.ft - c[i].O.ft);
    eve[E++] = Teve(bb,B,1), eve[E++] = Teve(aa,A,-1);
          if(B > A) ++cnt;
        }
      if(E == 0) Area[cnt] += PI * c[i].R * c[i].R;
      else{
        sort(eve, eve + E);
        eve[E] = eve[0];
        for(int j = 0; j < E; ++j){
          cnt += eve[j].add;
          Area[cnt] += cross(eve[j].p, eve[j+1].p) *.5;
          Dt ang = eve[j + 1].ang - eve[j].ang;
          if (ang < 0) ang += 2. * PI;
          Area[cnt] += (ang-sin(ang))*c[i].R*c[i].R*.5;
        }
      }
    }
  }
};

bool isin( Line l0, Line l1, Line l2 ) {
  // Check inter(l1, l2) in l0
  Pt p = intersect(l1.ft, l1.sd, l2.ft, l2.sd);
  return cross(l0.sd - l0.ft, p - l0.ft) > eps;
}
/* If no solution, check: 1. ret.size() < 3
 * Or more precisely, 2. interPnt(ret[0], ret[1])
 * in all the lines. (use (l.sd - l.ft) ^ (p - l.ft) >0
 */
/* --^-- Line.ft --^-- Line.sd --^-- */
vector<Line> halfPlaneInter(vector<Line> lines) {
  int sz = lines.size();
  vector<ld> ata(sz), ord(sz);
  for(int i = 0; i < sz; ++i) {
    ord[i] = i;
    Vt d = lines[i].sd - lines[i].ft;
    ata[i] = atan2(d.sd, d.ft);
  }
  sort(ord.begin(), ord.end(), [&](int i, int j) {
      if ( isZ(ata[i] - ata[j]) )
          return cross(lines[i].sd - lines[i].ft,
            lines[j].sd - lines[i].ft) < 0;
      return ata[i] < ata[j];
  });
  vector<Line> fin;
  for (int i = 0; i < sz; ++i)
    if (!i or !isZ(ata[ord[i]] - ata[ord[i-1]]))
      fin.emplace_back(lines[ord[i]]);
  deque<Line> dq;
  for (int i = 0; i < fin.size(); i++){
    while(dq.size() >= 2 and !isin(fin[i],
        dq[dq.size()-2], dq.back()))  dq.pop_back();
    while(dq.size() >= 2 and !isin(fin[i],
        dq[0], dq[1]))  dq.pop_front();
    dq.push_back(fin[i]);
  }
  while(dq.size() >= 3 and !isin(dq[0],
        dq[dq.size()-2], dq.back()))  dq.pop_back();
  while(dq.size() >= 3 and !isin(dq.back(),
        dq[0], dq[1]))  dq.pop_front();
  vector<Line> res(ALL(dq));
  return res;
}

int z[MAXn];
void make_z(string s) {
  int l = 0, r = 0;
  for (int i = 1, sz = s.size(); i < sz; i++) {
    z[i] = max(0, min(r - i + 1, z[i - l]));
    while (i + z[i] < sz and s[i + z[i]] == s[z[i]])
         z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
}

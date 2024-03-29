int z[MAXN*2+1];
int Manacher(string tmp) {
  string s = "&";
  int l = 0, r = 0, x, ans;
  for (char c : tmp) s += c, s += '%';
  ans = 0, x = 0;
  const int sz = s.size();
  for (int i = 1; i < sz; i++) {
    z[i] = r > i ? min(z[2 * l - i], r - i) : 1;
    while (s[i + z[i]] == s[i - z[i]]) ++z[i];
    if (z[i] + i > r) r = z[i] + i, l = i;
  }
  for (int i = 1; i < sz; i++)
    if (s[i] == '%') x = max(x, z[i]);
  ans = x / 2 * 2, x = 0;
  for (int i = 1; i < sz; i++)
    if (s[i] != '%') x = max(x, z[i]);
  return max(ans, (x - 1) / 2 * 2 + 1);
}

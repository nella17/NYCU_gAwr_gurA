int F[MAXN];
vector<int> match(auto A, auto B) {
  const int Asz = A.size(), Bsz = B.size();
  vector<int> ans{};
  F[0] = -1, F[1] = 0;
  for (int i = 1, j = 0; i < Bsz; F[++i] = ++j) {
    if (B[i] == B[j]) F[i] = F[j]; // optimize
    while (j != -1 and B[i] != B[j]) j = F[j];
  }
  for (int i = 0, j = 0; i < Asz; ++i) {
    while (j != -1 and A[i] != B[j]) j = F[j];
    if (++j == Bsz) ans.emplace_back(i-j), j = F[j];
  }
  return ans;
}

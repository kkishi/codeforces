#include <bits/stdc++.h>

#include "codeforces.h"
#include "graph.h"
#include "topological_sort.h"

void Main() {
  ints(m, n);
  V<int> p(n);
  cin >> p;
  vector r(m, vector(n, int(0)));
  cin >> r;

  using B = bitset<5000>;
  V<B> v(n);
  rep(i, n) rep(j, n) v[i][j] = 1;

  rep(c, m) {
    V<int> idx(n);
    iota(all(idx), 0);
    const V<int>& R = r[c];
    sort(all(idx), [&](int i, int j) { return R[i] < R[j]; });
    B ok;
    rep(i, n) ok[i] = 1;
    int i = n - 1;
    while (i >= 0) {
      int k = i;
      while (k >= 0 && R[idx[k]] == R[idx[i]]) {
        ok[idx[k]] = 0;
        --k;
      }
      rep(j, k + 1, i + 1) v[idx[j]] &= ok;
      i = k;
    }
  }

  Graph g(n);
  rep(i, n) rep(j, n) if (v[i][j]) g[i].eb(j);
  auto [t, ok] = TopologicalSort(g);
  assert(ok);
  reverse(t);
  V<int> dp = p;
  each(e, t) each(c, g[e]) chmax(dp[e], dp[c] + p[e]);
  wt(max(dp));
}

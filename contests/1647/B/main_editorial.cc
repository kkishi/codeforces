#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "cumulative_sum.h"

void Main() {
  wt([] {
    ints(n, m);
    V<string> g(n);
    cin >> g;
    vector G(n, vector(m, int(0)));
    rep(i, n) rep(j, m) G[i][j] = g[i][j] - '0';
    CumulativeSum2D s(G);
    rep(i, n - 1) rep(j, m - 1) {
      if (s.Get(i, j, i + 1, j + 1) == 3) return false;
    }
    return true;
  }());
}

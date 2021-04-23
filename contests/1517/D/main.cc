#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n, m, k);
  if (!even(k)) {
    rep(n) wt(V<int>(m, -1));
    return;
  }
  vector rc(n, vector(m - 1, int(0)));
  cin >> rc;
  vector cc(n - 1, vector(m, int(0)));
  cin >> cc;
  auto edge = [&](int i, int j, int ni, int nj) {
    if (i == ni) {
      if (j > nj) swap(j, nj);
      assert(j + 1 == nj);
      return rc[i][j];
    } else {
      assert(j == nj);
      if (i > ni) swap(i, ni);
      assert(i + 1 == ni);
      return cc[i][j];
    }
  };
  vector dp(k / 2 + 1, vector(n, vector(m, big)));
  rep(i, n) rep(j, m) dp[0][i][j] = 0;
  rep(i, k / 2) rep(r, n) rep(c, m)
      each(nr, nc, adjacent(r, c)) if (inside(nr, nc, n, m))
          chmin(dp[i + 1][r][c], dp[i][nr][nc] + edge(r, c, nr, nc) * 2);
  each(e, dp[k / 2]) wt(e);
}

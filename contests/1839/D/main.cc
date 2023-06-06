#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> c(n);
  cin >> c;
  {
    V<int> nc;
    nc.eb(0);
    each(e, c) nc.eb(e);
    nc.eb(n + 1);
    swap(c, nc);
    n += 2;
  }
  vector dp(n, vector(n + 1, big));
  dp[0][0] = 0;
  rep(i, n) rep(j, n) {
    chmin(dp[i][j + 1], dp[i][j]);
    rep(k, i + 1, n) {
      if (c[i] < c[k]) {
        int skipped = k - i - 1;
        int nj = j + (skipped > 0);
        chmin(dp[k][nj], dp[i][j] + skipped);
      }
    }
  }
  V<int> ans;
  rep(i, 1, sz(dp[n - 1]) - 2) ans.eb(dp[n - 1][i]);
  wt(ans);
}

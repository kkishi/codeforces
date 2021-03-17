#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
  ints(l, r);
  auto f = [](int x) {
    V<int> v;
    if (x == 0) {
      v = {0};
    } else {
      while (x) {
        v.pb(x % 10);
        x /= 10;
      }
      reverse(all(v));
    }
    int n = sz(v);
    vector dp(n + 1, vector(2, vector(5, int(0))));
    dp[0][0][0] = 1;
    rep(i, n) rep(less, 2) rep(used, 4) rep(j, 10) {
      if (!less && j > v[i]) continue;
      dp[i + 1][less | (j < v[i])][used + (j > 0)] += dp[i][less][used];
    }
    int ret = 0;
    rep(i, 2) rep(j, 4) ret += dp[n][i][j];
    return ret;
  };
  wt(f(r) - f(l - 1));
}

void Main() {
  ints(t);
  rep(t) Solve();
}

#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
  ints(b, l, r);
  auto f = [&b](int x) {
    V<int> v;
    while (x) {
      v.pb(x % b);
      x /= b;
    }
    reverse(all(v));
    int n = sz(v);
    vector dp(n + 1, vector(2, vector(2, vector(1 << b, int(0)))));
    dp[0][0][0][0] = 1;
    rep(i, n) rep(lo, 2) rep(nz, 2) rep(mask, 1 << b) rep(j, b) {
      if (!lo && j > v[i]) continue;
      int nnz = nz | (j > 0);
      int nmask = mask;
      if (nnz) nmask ^= (1 << j);
      dp[i + 1][lo | (j < v[i])][nz | (j > 0)][nmask] += dp[i][lo][nz][mask];
    }
    int ans = 0;
    rep(i, 2) rep(j, 2) ans += dp[n][i][j][0];
    return ans;
  };
  wt(f(r) - f(l - 1));
}

void Main() {
  ints(t);
  rep(t) Solve();
}

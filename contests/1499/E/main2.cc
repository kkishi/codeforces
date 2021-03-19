#include <bits/stdc++.h>

#include "codeforces.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  strings(x, y);
  int sx = sz(x), sy = sz(y);
  vector dp(sx + 1, vector(sy + 1, vector(3, vector(2, vector(2, mint(0))))));
  mint ans = 0;
  rep(i, sx + 1) rep(j, sy + 1) {
    rep(k, 1, 3) ans += dp[i][j][k][1][1];
    ++dp[i][j][0][0][0];
    rep(k, 3) rep(l, 2) rep(m, 2) {
      mint v = dp[i][j][k][l][m];
      if (v == 0) continue;
      char c = 0;
      if (k == 1) c = x[i - 1];
      if (k == 2) c = y[j - 1];
      if (i < sx && c != x[i]) dp[i + 1][j][1][l | 1][m] += v;
      if (j < sy && c != y[j]) dp[i][j + 1][2][l][m | 1] += v;
    }
  }
  wt(ans);
}

#include <bits/stdc++.h>

#include "codeforces.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  strings(x, y);
  int sx = sz(x), sy = sz(y);
  vector dp(sx, vector(sy, vector(2, mint(0))));
  mint ans = 0;
  auto f = [](const string& s) {
    V<int> v(sz(s));
    v[0] = 1;
    rep(i, 1, sz(s)) v[i] = s[i] == s[i - 1] ? 1 : (v[i - 1] + 1);
    return v;
  };
  V<int> vx = f(x), vy = f(y);
  rep(i, sx) rep(j, sy) {
    if (i > 0) rep(k, 2) {
        char c = k == 0 ? y[j] : x[i - 1];
        char d = x[i];
        if (c != d) dp[i][j][1] += dp[i - 1][j][k];
      }
    if (j > 0) rep(k, 2) {
        char c = k == 0 ? y[j - 1] : x[i];
        char d = y[j];
        if (c != d) dp[i][j][0] += dp[i][j - 1][k];
      }
    rep(k, 2) {
      if (x[i] != y[j]) {
        mint m;
        if (k == 1) m = vy[j];
        if (k == 0) m = vx[i];
        dp[i][j][k] += m;
      }
      ans += dp[i][j][k];
    }
  }
  wt(ans);
}

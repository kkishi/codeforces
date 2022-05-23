#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n, x);
  vector dp(70, vector(50, vector(40, vector(40, big))));
  dp[0][0][0][0] = 0;
  int ans = big;
  rep(i, 60) rep(j, 40) rep(k, 30) rep(l, 30) {
    if (dp[i][j][k][l] == big) continue;
    int y = x;
    rep(i) y *= 2;
    rep(j) y *= 3;
    rep(k) y *= 5;
    rep(l) y *= 7;
    int Y = y;
    int keta = 0;
    V<bool> seen(10);
    while (Y) {
      seen[Y % 10] = true;
      Y /= 10;
      ++keta;
    }
    if (keta >= n) {
      chmin(ans, dp[i][j][k][l]);
      break;
    }
    rep(I, 10) if (seen[I]) {
      int w = I;
      auto f = [&](int p, int& i) {
        while (w > 0 && w % p == 0) {
          w /= p;
          ++i;
        }
      };
      int ni = i;
      f(2, ni);
      int nj = j;
      f(3, nj);
      int nk = k;
      f(5, nk);
      int nl = l;
      f(7, nl);
      chmin(dp[ni][nj][nk][nl], dp[i][j][k][l] + 1);
    }
  }
  if (ans == big) ans = -1;
  wt(ans);
}

#include <bits/stdc++.h>

#include <atcoder/modint>

#include "codeforces.h"

using mint = atcoder::modint;

ostream& operator<<(ostream& os, const mint& m) {
  os << m.val();
  return os;
}

void Main() {
  ints(n, m);
  mint::set_mod(m);
  vector dp(n + 1, mint(0));
  vector dx(n + 1, mint(0));
  mint x = 0;
  rep(i, 1, n + 1) {
    x += dx[i];
    if (i == 1) {
      // dp[1] is special - it is 1, although there's no way to move from 1 to 1
      // based on the game's rule.
      dp[i] = 1;
    } else {
      dp[i] = x;
    }
    dx[i + 1] += dp[i];
    for (int j = i * 2; j <= n; j += i) {
      dx[j] -= dp[i - 1];
      dx[j] += dp[i];
    }
  }
  wt(dp[n]);
}

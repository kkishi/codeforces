#include <bits/stdc++.h>

#include "codeforces.h"
#include "matrix.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  vector dp(200101, vector(10, mint(0)));
  dp[0][0] = 1;
  rep(i, sz(dp) - 1) {
    rep(j, 9) dp[i + 1][j + 1] += dp[i][j];
    dp[i + 1][0] += dp[i][9];
    dp[i + 1][1] += dp[i][9];
  }
  vector mul(sz(dp), mint(0));
  rep(i, sz(dp)) mul[i] = accumulate(all(dp[i]), mint(0));

  ints(t);
  rep(t) {
    ints(n, m);
    mint ans = 0;
    while (n) {
      ans += mul[max(0, m + n % 10)];
      n /= 10;
    }
    wt(ans);
  }
}

#include <bits/stdc++.h>

#include "codeforces.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, k);
  V<mint> dp(n + 1);
  dp[0] = 1;
  V<mint> ans(n);
  rep(i, k, n + 1) {
    V<mint> ndp(n + 1);
    rep(j, n + 1 - i) ndp[j + i] = ndp[j] + dp[j];
    swap(dp, ndp);
    if (accumulate(dp) == 0) break;
    rep(j, n) ans[j] += dp[j + 1];
  }
  wt(ans);
}

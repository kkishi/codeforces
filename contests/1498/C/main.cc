#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  if (k == 1) {
    wt(1);
    return;
  }
  mint ans = 1 + n;  // 0, 1
  V<mint> dp(n);
  rep(i, n) dp[i] = 1;
  // 2 .. k - 1
  rep(iter, k - 2) {
    V<mint> ndp(n);
    if (even(iter)) {
      ndp[n - 1] = 0;
      rrep(i, n - 1) ndp[i] = ndp[i + 1] + dp[i + 1];
    } else {
      ndp[0] = 0;
      rep(i, n - 1) ndp[i + 1] = ndp[i] + dp[i];
    }
    ans += accumulate(all(ndp), mint(0));
    swap(dp, ndp);
  }
  wt(ans);
}

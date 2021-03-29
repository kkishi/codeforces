#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n, m);
  V<int> dp(m + 1, -1);
  dp[0] = 0;
  const int N = 100000;
  rep(iter, n) {
    ints(t, x, y);
    V<int> ndp = dp;
    if (t == 1) {
      int p = div_ceil(x, N);
      rrep(i, m + 1) if (dp[i] != -1) {
        rep(j, 1, y + 1) {
          int ni = i + p * j;
          if (ni > m) break;
          if (dp[ni] != -1) break;
          ndp[ni] = iter + 1;
        }
      }
    } else {
      rrep(i, m + 1) if (dp[i] != -1) {
        int p = i;
        rep(y) {
          p = div_ceil(p * x, N);
          if (p > m) break;
          if (dp[p] != -1) break;
          ndp[p] = iter + 1;
        }
      }
    }
    swap(dp, ndp);
  }
  V<int> ans(dp.begin() + 1, dp.end());
  wt(ans);
}

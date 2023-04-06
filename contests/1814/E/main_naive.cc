#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n);
  V<int> a(n - 1);
  cin >> a;
  ints(q);
  rep(q) {
    ints(k, x);
    a[k - 1] = x;
    vector dp(n, vector(2, int(0)));
    dp[0][0] = 0;
    dp[0][1] = big;
    rep(i, n - 1) {
      dp[i + 1][0] = dp[i][1];
      dp[i + 1][1] = min(dp[i][0], dp[i][1]) + 2 * a[i];
    }
    wt(dp[n - 1][1]);
  }
}

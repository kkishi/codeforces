#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> next(n);
  rrep(i, n) {
    if (a[i] == 0) {
      next[i] = i;
    } else {
      if (i + 1 < n) {
        next[i] = next[i + 1];
      } else {
        next[i] = big;
      }
    }
  }
  vector dp(n + 1, vector(n + 1, big));
  dp[0][0] = 0;
  rep(i, n) rep(j, n) {
    if (dp[i][j] == big) continue;
    chmin(dp[i][j + 1], dp[i][j]);
    if (a[i] == 0) {
      chmin(dp[i + 1][j], dp[i][j]);
    } else {
      int k = next[j];
      chmin(dp[i + 1][k + 1], dp[i][j] + abs(i - k));
    }
  }
  rrep(i, n) if (a[i] == 1) {
    wt(*min_element(all(dp[i + 1])));
    return;
  }
  wt(0);
}

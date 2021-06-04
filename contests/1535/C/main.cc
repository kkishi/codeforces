#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  strings(s);
  int ans = 0;
  int n = sz(s);
  vector dp(n + 1, vector(2, int(0)));
  rep(i, n) {
    rep(j, 2) {
      if (s[i] != '?' && s[i] - '0' != j) {
        dp[i + 1][j] = 0;
      } else {
        dp[i + 1][j] = 1 + dp[i][1 - j];
      }
    }
    ans += max(dp[i + 1][0], dp[i + 1][1]);
  }
  wt(ans);
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  vector del(n + 1, vector(n + 1, int(0)));
  rep(i, n) {
    del[i][i] = 1;
    V<int> cnt(n);
    int ma = 0;
    rep(j, i, n) {
      chmax(ma, ++cnt[a[j] - 1]);
      int l = j - i + 1;
      del[i][j + 1] = even(l) && ma <= l / 2;
    }
  }
  del[n][n] = 1;

  int ans = 0;
  V<int> dp(n);
  rep(i, n) {
    if (del[0][i]) dp[i] = 1;
    rep(j, i) if (a[j] == a[i] && dp[j] && del[j + 1][i]) {
      chmax(dp[i], dp[j] + 1);
    }
    if (del[i + 1][n]) {
      chmax(ans, dp[i]);
    }
  }
  wt(ans);
}

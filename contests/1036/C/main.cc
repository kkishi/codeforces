#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
  ints(l, r);
  auto f = [](int x) {
    V<int> v;
    if (x == 0) {
      v = {0};
    } else {
      while (x) {
        v.pb(x % 10);
        x /= 10;
      }
      reverse(all(v));
    }
    int n = sz(v);
    vector dp(n + 1, vector(2, vector(5, int(0))));
    dp[0][0][0] = 1;
    int cnt = 0;
    rep(i, n) {
      rep(used, 4) {
        int x = dp[i][1][used];
        dp[i + 1][1][used] += x;
        dp[i + 1][1][used + 1] += x * 9;
      }
      auto g = [&cnt](int x) { return min(4, cnt + (x > 0)); };
      rep(j, v[i]) dp[i + 1][1][g(j)] += 1;
      dp[i + 1][0][g(v[i])] += 1;
      if (v[i] > 0) ++cnt;
    }
    int ret = 0;
    rep(i, 2) rep(j, 4) ret += dp[n][i][j];
    return ret;
  };
  wt(f(r) - f(l - 1));
}

void Main() {
  ints(t);
  rep(t) Solve();
}

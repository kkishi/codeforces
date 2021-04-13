#include <bits/stdc++.h>

#include "codeforces.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  V<mint> dp(max(n, m) + 1);
  rep(i, 2, sz(dp)) {
    dp[i] = dp[i - 1] + dp[i - 2] + mint(2).Pow(i - 2) + dp[i - 2];
  }
  V<string> g(n);
  cin >> g;
  int tot = 0;
  rep(i, n) rep(j, m) if (g[i][j] == 'o')++ tot;
  map<int, int> cnt;
  rep(i, n) {
    int x = 0;
    rep(j, m) {
      if (g[i][j] == 'o') {
        ++x;
      } else {
        ++cnt[x];
        x = 0;
      }
    }
    ++cnt[x];
  }
  rep(i, m) {
    int x = 0;
    rep(j, n) {
      if (g[j][i] == 'o') {
        ++x;
      } else {
        ++cnt[x];
        x = 0;
      }
    }
    ++cnt[x];
  }
  mint ans = 0;
  for (auto [k, v] : cnt) {
    ans += dp[k] * mint(2).Pow(tot - k) * v;
  }
  wt(ans);
}

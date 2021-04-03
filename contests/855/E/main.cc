#include <bits/stdc++.h>

#include "codeforces_multi.h"

int dp[100][2][2][11];

void Main() {
  ints(b, l, r);
  auto f = [&b](int x) {
    V<int> v;
    while (x) {
      v.pb(x % b);
      x /= b;
    }
    reverse(all(v));
    int n = sz(v);
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    int mask = 0;
    rep(i, n) {
      rep(lo, 2) rep(nz, 2) rep(odd, b + 1) {
        int x = dp[i][lo][nz][odd];
        if (x == 0) continue;
        if (lo) {
          if (nz) {
            if (odd < b) dp[i + 1][1][1][odd + 1] += x * (b - odd);
            if (odd > 0) dp[i + 1][1][1][odd - 1] += x * odd;
          } else {
            assert(x == 1);
            dp[i + 1][1][0][0] += x;            // 0
            dp[i + 1][1][1][1] += (b - 1) * x;  // non-zero
          }
        } else {
          assert(x == 1);
          rep(j, v[i]) {
            if (j == 0) {
              dp[i + 1][1][nz][nz ? popcount(mask ^ 1) : 0] += x;
            } else {
              dp[i + 1][1][1][popcount(mask ^ (1 << j))] += x;
            }
          }
          dp[i + 1][0][1][popcount(mask ^ (1 << v[i]))] += x;
        }
      }
      mask ^= 1 << v[i];
    }
    int ans = 0;
    rep(i, 2) rep(j, 2) ans += dp[n][i][j][0];
    return ans;
  };
  wt(f(r) - f(l - 1));
}

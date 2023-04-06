#include <bits/stdc++.h>

#include "codeforces.h"
#include "int_sqrt.h"

int dp[200005][2];

void Main() {
  ints(n);
  --n;
  V<int> a(n);
  cin >> a;
  int B = IntSqrt(n);
  int N = div_ceil(n, B);
  using A = array<int, 4>;
  V<A> bs(N);
  auto f = [&](int bi) {
    int l = bi * B;
    int r = min(l + B, n);
    int n = r - l;
    A ret;
    rep(cancut, 2) {
      dp[0][0] = cancut == 0 ? 0 : big;
      dp[0][1] = cancut == 0 ? big : 0;
      rep(i, n) {
        dp[i + 1][0] = dp[i][1];
        dp[i + 1][1] = min(dp[i][0], dp[i][1]) + 2 * a[l + i];
      }
      rep(i, 2) ret[cancut * 2 + i] = dp[n][i];
    }
    return ret;
  };
  rep(i, N) bs[i] = f(i);
  ints(q);
  rep(q) {
    ints(k, x);
    --k;
    a[k] = x;
    int i = k / B;
    bs[i] = f(i);
    dp[0][0] = 0;
    dp[0][1] = big;
    rep(i, N) {
      dp[i + 1][0] = min(dp[i][0] + bs[i][0], dp[i][1] + bs[i][2]);
      dp[i + 1][1] = min(dp[i][0] + bs[i][1], dp[i][1] + bs[i][3]);
    }
    wt(dp[N][1]);
  }
}

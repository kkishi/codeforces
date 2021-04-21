#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  while (true) {
    int sum = accumulate(all(a), int(0));
    if (!even(sum)) {
      wt(0);
      return;
    }
    V<bool> dp(sum + 1);
    dp[0] = true;
    rep(i, n) { rrep(j, sum + 1 - a[i]) if (dp[j]) dp[j + a[i]] = true; }
    if (!dp[sum / 2]) {
      wt(0);
      return;
    }
    int odd_i = -1;
    rep(i, n) if (!even(a[i])) odd_i = i;
    if (odd_i != -1) {
      wt(1);
      wt(odd_i + 1);
      return;
    }
    each(e, a) e /= 2;
  }
}

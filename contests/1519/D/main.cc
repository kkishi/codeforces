#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  int tot = 0;
  rep(i, n) tot += a[i] * b[i];
  int ans = tot;
  rep(center, 0, n) {
    rep(d, 2) {  // 0: Odd, 1: Even
      int sum = 0;
      for (int width = 1;; ++width) {
        int l = center - (width - d);
        int r = center + width;
        if (l < 0 || n <= r) break;
        sum += (b[l] - b[r]) * (a[r] - a[l]);
        chmax(ans, sum + tot);
      }
    }
  }
  wt(ans);
}

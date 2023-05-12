#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "cumulative_sum.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  sort(a);

  int sum = accumulate(a);
  CumulativeSum1D c(a);
  int ans = -big;
  for (int i = 0; i * 2 <= n && i <= k; ++i) {
    chmax(ans, sum - c.Get(0, i * 2 - 1) - c.Get(n - (k - i), n - 1));
  }
  wt(ans);
}

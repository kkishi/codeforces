#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, q);
  strings(s);
  V<int> sum(n + 1);
  rep(i, n) {
    int x = s[i] == '+' ? 1 : -1;
    if (!even(i)) x = -x;
    sum[i + 1] = sum[i] + x;
  }
  rep(q) {
    ints(l, r);
    int x = sum[r] - sum[l - 1];
    if (x == 0) {
      wt(0);
    } else if (even(x)) {
      wt(2);
    } else {
      wt(1);
    }
  }
}

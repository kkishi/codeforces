#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(a, b);
  int ans = big;
  for (int m = 1; m <= 1000000; ++m) {
    chmin(ans, m - 1 + div_ceil(a, m) + div_ceil(b, m));
  }
  wt(ans);
}

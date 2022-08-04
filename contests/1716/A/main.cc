#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  int x = n / 3;
  int ans = big;
  rep(i, -5, 6) rep(j, -5, 6) {
    if (3 * (x + i) + 2 * j == n) {
      chmin(ans, abs(x + i) + abs(j));
    }
  }
  wt(ans);
}

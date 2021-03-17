#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
  ints(n, k);
  if (!even(n)) {
    wt(1, (n - 1) / 2, (n - 1) / 2);
    return;
  }
  int r = n % 4;
  if (r == 2) {
    wt(2, n / 2 - 1, n / 2 - 1);
    return;
  }
  if (n == 4) {
    wt(1, 1, 2);
    return;
  }
  int l = n / 4;
  int x = 4;
  while (even(l) && l > 2) {
    x *= 2;
    l /= 2;
  }
  wt(x, (n - x) / 2, (n - x) / 2);
}

void Main() {
  ints(t);
  rep(t) Solve();
}

#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
  ints(n, k1, k2);
  ints(w, b);
  auto f = [](int x, int y, int z) {
    int m = min(x, y);
    return m + (x - m) / 2 + (y - m) / 2 >= z;
  };
  wt(f(k1, k2, w) && f(n - k1, n - k2, b));
}

void Main() {
  ints(t);
  rep(t) Solve();
}

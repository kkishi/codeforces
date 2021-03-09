#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
  ints(n, k);
  --k;
  if (even(n)) {
    wt(k % n + 1);
    return;
  }
  int d = (n - 1) / 2;
  int x = k / d;
  wt((k + x) % n + 1);
}

void Main() {
  ints(t);
  rep(t) Solve();
}

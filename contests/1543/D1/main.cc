#include <bits/stdc++.h>

#include "codeforces_interactive.h"

void Solve() {
  ints(n, k);
  dbg(n, k);
  int X = 0;
  rep(i, n) {
    int y = X ^ i;
    dbg(i, X, y);
    wt_flush(y);
    ints(r);
    dbg(r);
    if (r == 1) return;
    X ^= y;
  }
}

void Main() {
  ints(t);
  dbg(t);
  rep(t) Solve();
}

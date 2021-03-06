#include <bits/stdc++.h>

#include "codeforces.h"

bool Solve() {
  strings(s);
  each(x, s) x -= 'A';
  rep(i, 2) rep(j, 2) rep(k, 2) {
    bool ok = true;
    V<int> inc{i, j, k};
    int x = 0;
    each(c, s) {
      if (inc[c] == 0) {
        ++x;
      } else {
        --x;
      }
      if (x < 0) ok = false;
    }
    if (x != 0) ok = false;
    if (ok) return true;
  }
  return false;
}

void Main() {
  ints(t);
  rep(t) wt(Solve());
}

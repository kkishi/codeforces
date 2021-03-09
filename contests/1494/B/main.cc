#include <bits/stdc++.h>

#include "codeforces.h"

bool Solve() {
  ints(n, u, r, d, l);
  rep(ul, 2) rep(ur, 2) rep(dl, 2) rep(dr, 2) {
    int U = u - (ul + ur);
    int R = r - (ur + dr);
    int D = d - (dl + dr);
    int L = l - (ul + dl);
    auto f = [&n](int x) { return 0 <= x && x <= n - 2; };
    if (f(U) && f(R) && f(D) && f(L)) return true;
  }
  return false;
}

void Main() {
  ints(t);
  rep(t) wt(Solve());
}

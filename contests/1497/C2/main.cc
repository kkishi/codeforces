#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
  ints(n, k);
  rep(k - 3) cout << "1 ";
  n -= k - 3;
  if (!even(n)) {
    wt(1, (n - 1) / 2, (n - 1) / 2);
    return;
  }
  int r = n % 4;
  if (r == 2) {
    wt(2, n / 2 - 1, n / 2 - 1);
    return;
  }
  wt(n / 4, n / 4, n / 2);
}

void Main() {
  ints(t);
  rep(t) Solve();
}

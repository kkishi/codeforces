#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
  ints(n);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  V<int> tm(n);
  cin >> tm;
  int ans = a[0] + tm[0];
  rep(i, n - 1) {
    int dep = ans + div_ceil(b[i] - a[i], 2);
    chmax(dep, b[i]);
    ans = dep + a[i + 1] - b[i] + tm[i + 1];
  }
  wt(ans);
}

void Main() {
  ints(t);
  rep(t) Solve();
}

#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> m;
  each(e, a)++ m[e];
  V<int> b;
  each(k, v, m) {
    b.pb(k);
    --v;
  }
  each(k, v, m) rep(v) b.pb(k);
  wt(b);
}

void Main() {
  ints(t);
  rep(t) Solve();
}

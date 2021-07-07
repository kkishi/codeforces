// This solution is not correct.
#include <bits/stdc++.h>

#include "codeforces_interactive.h"

V<int> conv(int n, int k) {
  V<int> v;
  if (n == 0) {
    v.pb(0);
  } else {
    while (n) {
      v.pb(n % k);
      n /= k;
    }
    reverse(all(v));
  }
  return v;
}

V<int> xr(const V<int>& a, const V<int>& b, int k) {
  int n = sz(a);
  V<int> c(n);
  rep(i, n) c[i] = (a[i] + b[i]) % k;
  return c;
}

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
  int k = 3;
  V<int> a = conv(100, k);
  dbg(a);
  V<int> b = conv(120, k);
  dbg(b);
  V<int> c = xr(a, b, k);
  dbg(c);
  V<int> d = xr(c, b, k);
  dbg(d);
  ints(t);
  dbg(t);
  rep(t) Solve();
}

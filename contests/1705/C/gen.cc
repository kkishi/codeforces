#include <bits/stdc++.h>

#include "codeforces.h"
#include "rand.h"

void Main() {
  wt(1);
  int n = 10, c = 10, q = 10;
  wt(n, c, q);
  string s;
  Rand r;
  rep(n) s += r.Alpha();
  wt(s);
  rep(c) {
    int L = r.Int(1, sz(s));
    int R = r.Int(1, sz(s));
    if (L > R) swap(L, R);
    wt(L, R);
  }
  rep(q) { wt(r.Int(1, sz(s))); }
}

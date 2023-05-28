#include <bits/stdc++.h>

#include "codeforces.h"
#include "rand.h"

Rand r;

void Main() {
  int t = 1;
  wt(t);
  int n = r.Int(2, 10);
  wt(n);
  V<int> a, b;
  rep(n) {
    a.eb(r.Int(1, n));
    b.eb(r.Int(1, n));
  }
  wt(a);
  wt(b);
}

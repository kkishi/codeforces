#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, s1, s2);
  V<pair<int, int>> r;
  rep(i, n) {
    ints(ri);
    r.eb(ri, i);
  }
  sort(r, greater{});
  V<int> a, b;
  each(x, i, r) {
    int A = (sz(a) + 1) * s1;
    int B = (sz(b) + 1) * s2;
    (A < B ? a : b).eb(i + 1);
  }
  if (sz(a)) {
    cout << sz(a) << " ";
    wt(a);
  } else {
    wt(0);
  }
  if (sz(b)) {
    cout << sz(b) << " ";
    wt(b);
  } else {
    wt(0);
  }
}

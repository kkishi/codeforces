#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "divisors.h"

void Main() {
  ints(k);
  strings(n);
  each(e, n) e -= '0';
  map<int, int> m;
  each(e, n)++ m[e];
  {
    V<int> v = {1, 4, 6, 8, 9};
    each(e, v) if (m[e] > 0) {
      wt(1);
      wt(e);
      return;
    }
  }
  {
    V<int> v = {2, 3, 5, 7};
    each(e, v) if (m[e] >= 2) {
      wt(2);
      wt(e * 10 + e);
      return;
    }
  }
  assert(k <= 4);
  rep(mask, 1 << k) {
    int x = 0;
    if (popcount(mask) < 2) continue;
    rep(i, k) if (hasbit(mask, i)) {
      x *= 10;
      x += n[i];
    }
    if (sz(Divisors(x)) > 2) {
      wt(popcount(mask));
      wt(x);
      return;
    }
  }
}

#include <bits/stdc++.h>

#include "codeforces.h"
#include "intervals.h"

void Main() {
  ints(n, q);
  Intervals is;
  is.Insert(0, n);
  int ans = n;
  rep(q) {
    ints(l, r, k);
    --l;
    each(i, is.Erase(l, r)) ans -= i.right - i.left;
    if (k == 2) {
      is.Insert(l, r);
      ans += r - l;
    }
    wt(ans);
  }
}

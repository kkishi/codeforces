#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> c(n);
  cin >> c;
  V<int> lis;
  each(e, c) {
    auto it = lower_bound(all(lis), e);
    if (it == lis.end()) {
      lis.eb(e);
    } else {
      *it = e;
    }
  }
  dbg(n - sz(lis));
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  wt([] {
    ints(x);
    --x;
    V<int> v(3);
    cin >> v;
    each(e, v)-- e;
    rep(3) {
      if (x == -1) return false;
      x = v[x];
    }
    return true;
  }());
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  for (int l = 1; l < n; ++l) {
    int x = 0;
    rep(i, l) x ^= a[i];
    int y = 0;
    bool clear = true;
    rep(i, l, n) {
      y ^= a[i];
      clear = false;
      if (y == x) {
        y = 0;
        clear = true;
      }
    }
    if (clear) {
      wt("YES");
      return;
    }
  }
  wt("NO");
}

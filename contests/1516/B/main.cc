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
    bool ok = false;
    rep(i, l, n) {
      y ^= a[i];
      if (y == x) {
        y = 0;
        ok = true;
      }
    }
    if (y == 0 && ok) {
      wt("YES");
      return;
    }
  }
  wt("NO");
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  rep(i, n + 1) {
    bool ok = true;
    rep(j, n) {
      if (a[j] > a[j + 1]) {
        ok = false;
        if (even(i) && (!even(j) || j >= n - 2)) continue;
        if (!even(i) && (even(j) || j >= n - 1)) continue;
        swap(a[j], a[j + 1]);
      }
    }
    if (ok) {
      wt(i);
      return;
    }
  }
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  V<pair<int, int>> ans;
  rep(i, n) {
    bool found = false;
    rep(j, i, n) {
      bool ok = true;
      rep(k, i, n) {
        if (a[j] > a[k] || b[j] > b[k]) {
          ok = false;
        }
      }
      if (ok) {
        if (i != j) {
          swap(a[i], a[j]);
          swap(b[i], b[j]);
          ans.eb(i + 1, j + 1);
        }
        found = true;
        break;
      }
    }
    if (!found) {
      wt(-1);
      return;
    }
  }
  wt(sz(ans));
  each(i, j, ans) wt(i, j);
}

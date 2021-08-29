#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<pair<int, int>> cave;
  rep(i, n) {
    ints(k);
    V<int> a(k);
    cin >> a;
    int entry = 1;
    rep(i, k) {
      int level = entry + i;
      if (level <= a[i]) {
        entry += (a[i] - level) + 1;
      }
    }
    cave.eb(entry, k);
  }
  sort(all(cave));
  int entry = 1;
  int ksum = 0;
  each(e, k, cave) {
    int level = entry + ksum;
    if (level < e) {
      entry += e - level;
    }
    ksum += k;
  }
  wt(entry);
}

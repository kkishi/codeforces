#include <bits/stdc++.h>

#include "codeforces_interactive.h"

void Main() {
  ints(n);
  V<int> k(n);
  cin >> k;
  V<tuple<int, int, int>> ps;
  rep(i, n - 1) rep(j, i + 1, n) ps.eb(abs(k[i] - k[j]), i, j);
  sort(all(ps), greater{});
  for (auto [d, i, j] : ps) {
    if (k[i] < k[j]) swap(i, j);
    wt_flush('?', i + 1, j + 1);
    strings(res);
    if (res == "Yes") {
      wt_flush('!', i + 1, j + 1);
      return;
    }
  }
  wt_flush("! 0 0");
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, m);
  V<string> g(n);
  cin >> g;
  if (g[0][0] == '1') {
    wt(-1);
    return;
  }
  V<tuple<int, int, int, int>> ans;
  rep(i, n) rrep(j, 1, m) if (g[i][j] == '1') ans.eb(i, j - 1, i, j);
  rrep(i, 1, n) if (g[i][0] == '1') ans.eb(i - 1, 0, i, 0);
  wt(sz(ans));
  for (auto [i, j, k, l] : ans) {
    wt(i + 1, j + 1, k + 1, l + 1);
  }
}

#include <bits/stdc++.h>

#include "binary_search.h"
#include "codeforces_multi.h"

void Main() {
  ints(m);
  vector a(2, vector(m, int(0)));
  cin >> a;
  int x = BinarySearch<int>(1000000000, -1, [&](int x) {
    int r = 0, c = 0;
    rep(i, m) {
      int nr = 1 - r;
      int nc = c;
      if (i == m - 1) {
        return a[nr][nc] <= x;
      }
      int nnr = nr;
      int nnc = nc + 1;
      // Prefer zig zag move.
      if (a[nr][nc] <= x && a[nnr][nnc] <= x + 1) {
        r = nnr;
        c = nnc;
        x += 2;
        continue;
      }
      auto move_to = [&](int nr, int nc) {
        if (a[nr][nc] > x) return false;
        ++x;
        r = nr, c = nc;
        return true;
      };
      const int oc = c;
      // (r, c) -> (r, m - 1) -> (1 - r, m - 1) -> (1 - r, c)
      while (c + 1 < m)
        if (!move_to(r, c + 1)) return false;
      if (!move_to(1 - r, c)) return false;
      while (c > oc)
        if (!move_to(r, c - 1)) return false;
      return true;
    }
    assert(false);
  });
  wt(x + m * 2 - 1);
}

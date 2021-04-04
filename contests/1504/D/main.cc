#include <bits/stdc++.h>

#include "codeforces_interactive.h"

void Main() {
  ints(n);
  vector g(n, vector(n, int(-1)));
  rep(n * n) {
    ints(a);
    auto [b, i, j] = [&]() -> tuple<int, int, int> {
      if (a != 2) {
        rep(i, n) rep(j, n) if (even(i + j) && g[i][j] == -1) {
          g[i][j] = 2;
          return {2, i, j};
        }
      }
      if (a != 1) {
        rep(i, n) rep(j, n) if (!even(i + j) && g[i][j] == -1) {
          g[i][j] = 1;
          return {1, i, j};
        }
      }
      rep(i, n) rep(j, n) if (g[i][j] == -1) {
        int b = even(i + j) ? 2 : 1;
        if (b == a) b = 3;
        g[i][j] = b;
        return {b, i, j};
      }
    }();
    rep(i, n) dbg(g[i]);
    wt_flush(b, i + 1, j + 1);
  }
}

#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n);
  vector g(n, vector(n, 0));
  rep(i, n) {
    ints(p);
    int r = i, c = i;
    g[r][c] = p;
    rep(p - 1) {
      if (c > 0 && g[r][c - 1] == 0) {
        --c;
      } else {
        ++r;
        assert(r < n);
        assert(g[r][c] == 0);
      }
      g[r][c] = p;
    }
  }
  rep(i, n) {
    rep(j, i + 1) {
      if (j) cout << ' ';
      cout << g[i][j];
    }
    cout << endl;
  }
}

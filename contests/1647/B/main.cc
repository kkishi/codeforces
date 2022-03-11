#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "cumulative_sum.h"

void Main() {
  wt([] {
    ints(n, m);
    V<string> g(n);
    cin >> g;
    vector G(n, vector(m, int(0)));
    rep(i, n) rep(j, n) G[i][j] = g[i][j] - '0';
    CumulativeSum2D s(G);
    rep(i, n) rep(j, m) rep(k, i, n) rep(l, j, m) {
      auto black = [&](int i, int j, int k, int l) {
        return (k - i + 1) * (l - j + 1) == s.Get(i, j, k, l);
      };
      if (black(i, j, k, l)) {
        bool ok = true;
        if (black(i, j, k + 1, l)) ok = false;
        if (black(i, j, k, l + 1)) ok = false;
        if (black(i - 1, j, k, l)) ok = false;
        if (black(i, j - 1, k, l)) ok = false;
        if (ok) {
          auto blackcell = [&](int i, int j) {
            return inside(i, j, n, m) && g[i][j] == '1';
          };
          rep(I, i, k + 1) {
            if (blackcell(I, j - 1)) return false;
            if (blackcell(I, l + 1)) return false;
          }
          rep(J, j, l + 1) {
            if (blackcell(i - 1, J)) return false;
            if (blackcell(k + 1, J)) return false;
          }
        }
      }
    }
    return true;
  }());
}

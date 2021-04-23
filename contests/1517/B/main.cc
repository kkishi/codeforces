#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, m);
  vector b(n, vector(m, int(0)));
  cin >> b;
  V<tuple<int, int, int>> path;
  rep(i, n) rep(j, m) path.eb(b[i][j], i, j);
  sort(all(path));
  int cost = 0;
  vector used(n, vector(m, false));
  vector p(m, vector(n, -1));
  rep(I, m) {
    auto [c, i, j] = path[I];
    cost += c;
    used[i][j] = true;
    p[I][i] = c;
  }
  dbg(cost);
  rep(i, n) rep(j, m) if (!used[i][j]) {
    rep(k, m) if (p[k][i] == -1) {
      p[k][i] = b[i][j];
      break;
    }
  }
  rep(i, n) {
    rep(j, m) {
      if (j) cout << " ";
      cout << p[j][i];
    }
    cout << endl;
  }
}

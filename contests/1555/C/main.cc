#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(m);
  vector a(2, vector(m, int(0)));
  cin >> a;
  int ans = big;
  vector sa(2, vector(m + 1, int(0)));
  rep(i, 2) rep(j, m) sa[i][j + 1] = sa[i][j] + a[i][j];
  rep(i, m) { chmin(ans, max(sa[1][i], sa[0][m] - sa[0][i + 1])); }
  wt(ans);
}

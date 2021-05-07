#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, m, k);
  vector dpmin(n + 1, vector(m + 1, big));
  vector dpmax(n + 1, vector(m + 1, -big));
  dpmin[0][0] = dpmax[0][0] = 0;
  rep(i, n) rep(j, m) {
    chmin(dpmin[i + 1][j], dpmin[i][j] + j + 1);
    chmin(dpmin[i][j + 1], dpmin[i][j] + i + 1);
    chmax(dpmax[i + 1][j], dpmax[i][j] + j + 1);
    chmax(dpmax[i][j + 1], dpmax[i][j] + i + 1);
  }
  wt(dpmin[n - 1][m - 1] <= k && k <= dpmax[n - 1][m - 1]);
}

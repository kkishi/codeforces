#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> l(n), r(n);
  rep(i, n) cin >> l[i] >> r[i];
  VV<int> g(n);
  rep(n - 1) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vector dp(n, vector(2, int(-1)));
  auto rec = Fix([&](auto rec, int node, int parent, int high) {
    int d = dp[node][high];
    if (d != -1) {
      return d;
    }
    d = 0;
    int x = high ? r[node] : l[node];
    each(child, g[node]) {
      if (child == parent) continue;
      int res = -big;
      rep(chigh, 2) {
        int cx = chigh ? r[child] : l[child];
        chmax(res, abs(x - cx) + rec(child, node, chigh));
      }
      d += res;
    }
    dp[node][high] = d;
    return d;
  });
  int ans = -big;
  rep(i, 2) chmax(ans, rec(0, -1, i));
  wt(ans);
}

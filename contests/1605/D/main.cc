#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  VV<int> g(n);
  rep(n - 1) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  V<int> C(n);
  Fix([&](auto rec, int node, int parent, int color) -> void {
    C[node] = color;
    each(child, g[node]) if (child != parent) rec(child, node, 1 - color);
  })(0, -1, 0);
  V<int> cnt(2);
  each(e, C)++ cnt[e];

  int I, CI;
  if (cnt[0] < cnt[1]) {
    I = 0;
    CI = cnt[0];
  } else {
    I = 1;
    CI = cnt[1];
  }
  VV<int> idx;
  rep(i, n) {
    int x = i + 1;
    int y = 63 - __builtin_clzll(x);
    if (sz(idx) < y + 1) idx.pb({});
    idx[y].pb(x);
  }
  rep(mask, 1 << sz(idx)) {
    int x = 0;
    rep(i, sz(idx)) if (hasbit(mask, i)) x += sz(idx[i]);
    if (x == CI) {
      VV<int> IDX(2);
      rep(i, sz(idx)) {
        int J = hasbit(mask, i) ? I : (1 - I);
        each(e, idx[i]) IDX[J].pb(e);
      }
      rep(i, 2) assert(cnt[i] == sz(IDX[i]));
      V<int> O(2);
      V<int> ans(n);
      rep(i, n) ans[i] = IDX[C[i]][O[C[i]]++];
      wt(ans);
      return;
    }
  }
  assert(false);
}

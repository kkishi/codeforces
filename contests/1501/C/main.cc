#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  const int N = 5000000;
  V<int> cnt(N + 1);
  each(e, a) chmin(++cnt[e], 4);

  map<int, int> m;
  each(e, cnt)++ m[e];

  auto yes = [](int x, int y, int z, int w) {
    wt("YES");
    wt(x + 1, y + 1, z + 1, w + 1);
    exit(0);
  };
  if (m[4] > 0) {
    rep(i, N + 1) if (cnt[i] == 4) {
      V<int> idx;
      rep(j, n) if (a[j] == i) idx.pb(j);
      yes(idx[0], idx[1], idx[2], idx[3]);
    }
  }
  if (m[2] + m[3] >= 2) {
    V<int> v;
    rep(i, N + 1) if (cnt[i] >= 2) v.pb(i);
    VV<int> idx(2);
    rep(i, n) rep(j, 2) if (a[i] == v[j]) idx[j].pb(i);
    yes(idx[0][0], idx[1][0], idx[0][1], idx[1][1]);
  }
  V<pair<int, int>> indice(N + 1);
  rep(i, n - 1) rep(j, i + 1, n) {
    int s = a[i] + a[j];
    auto [k, l] = indice[s];
    if (sz(set{i, j, k, l}) == 4) {
      yes(i, j, k, l);
    }
    indice[s] = {i, j};
  }
  wt("NO");
}

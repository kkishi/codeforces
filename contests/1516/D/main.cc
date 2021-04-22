#include <bits/stdc++.h>

#include "binary_search.h"
#include "codeforces.h"
#include "sieve.h"

Sieve s(100000);

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  map<int, vector<int>> pi;
  rep(i, n) each(k, _, s.Factors(a[i])) pi[k].pb(i);
  V<int> R(n, big);
  each(_, v, pi) rep(i, sz(v) - 1) chmin(R[v[i]], v[i + 1] - 1);
  rrep(i, n - 1) chmin(R[i], R[i + 1]);
  vector dbl(30, vector(n, int(0)));
  dbl[0] = R;
  rep(i, 30 - 1) rep(j, n) {
    int x = dbl[i][j];
    if (x != big) x = dbl[i][x + 1];
    dbl[i + 1][j] = x;
  }
  rep(q) {
    ints(l, r);
    --l;
    wt(BinarySearch<int>(n, 0, [&](int x) {
      int idx = l - 1;
      rep(i, 30) if (hasbit(x, i)) {
        if (idx != big) idx = dbl[i][idx + 1];
      }
      return idx >= r - 1;
    }));
  }
}

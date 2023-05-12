#include <bits/stdc++.h>

#include <atcoder/modint>

#include "codeforces.h"

using mint = atcoder::modint998244353;

ostream& operator<<(ostream& os, mint x) {
  os << x.val();
  return os;
}

void Main() {
  ints(n, a1, x, y, m, k);
  V<int> a(n);
  a[0] = a1;
  rep(i, 1, n) a[i] = (a[i - 1] * x + y) % m;

  V<mint> fact(n + 1, 1);
  rep(i, 1, sz(fact)) fact[i] = fact[i - 1] * i;

  auto C = [&](int x, int y) -> mint {
    if (x < y) return 0;
    return fact[x] / (fact[y] * fact[x - y]);
  };

  V<mint> b(n);
  rep(i, n) rep(j, i + 1) b[i] += C(i + 1 - j, k) * a[j];

  int ans = 0;
  rep(i, n) ans ^= b[i].val() * (i + 1);
  wt(ans);
}

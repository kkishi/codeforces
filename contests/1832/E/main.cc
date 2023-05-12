#include <bits/stdc++.h>
#include <convolution_large.h>

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

  const int N = n + 1;
  V<mint> fact(N, 1), inv(N, 1), ifact(N, 1);
  rep(i, 2, N) {
    fact[i] = fact[i - 1] * i;
    inv[i] = mint::mod() / i * -inv[mint::mod() % i];
    ifact[i] = ifact[i - 1] * inv[i];
  }

  V<mint> f(n);
  rep(i, sz(f)) {
    int j = i + 1 - k;
    if (j >= 0) f[i] = fact[i + 1] * ifact[j];
  }

  V<mint> g(n);
  rep(i, n) g[i] = a[i];

  V<mint> c = suisen::convolution_large(f, g);

  V<mint> b(n);
  rep(i, n) b[i] = c[i] * ifact[k];

  int ans = 0;
  rep(i, n) ans ^= b[i].val() * (i + 1);
  wt(ans);
}

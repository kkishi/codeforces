#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, m);
  const int N = 30;
  V<array<int, N>> b(n + 1);
  rep(m) {
    ints(l, r, x);
    --l;
    rep(i, N) if (!hasbit(x, i)) {
      ++b[l][i];
      --b[r][i];
    }
  }

  V<int> a(n);
  array<int, N> cum = b[0];
  rep(i, n) {
    rep(j, N) if (cum[j] == 0) a[i] |= (1 << j);
    rep(j, N) cum[j] += b[i + 1][j];
  }
  mint ans = 0;
  rep(i, 30) {
    int one = 0;
    rep(j, n) if (hasbit(a[j], i))++ one;
    mint cnt = 0;
    for (int j = 1; j <= one; j += 2) {
      cnt += mint::Comb(one, j) * mint(2).Pow(n - one);
    }
    ans += mint(2).Pow(i) * cnt;
  }
  wt(ans);
}

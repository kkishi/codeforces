#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, m);
  V<tuple<int, int, int>> v;
  rep(m) {
    ints(l, r, x);
    v.eb(l, r, x);
  }
  mint ans = 0;
  rep(bit, 30) {
    V<int> b(n + 1);
    for (auto [l, r, x] : v) {
      if (!hasbit(x, bit)) {
        ++b[l - 1];
        --b[r];
      }
    }
    int one = 0;
    int cnt = b[0];
    rep(i, n) {
      if (cnt == 0) ++one;
      cnt += b[i + 1];
    }
    mint sum = 0;
    for (int j = 1; j <= one; j += 2) {
      sum += mint::Comb(one, j) * mint(2).Pow(n - one);
    }
    ans += mint(2).Pow(bit) * sum;
  }
  wt(ans);
}

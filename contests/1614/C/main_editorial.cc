#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, m);
  int X = 0;
  rep(m) {
    ints(l, r, x);
    X |= x;
  }
  mint ans = 0;
  rep(i, 30) if (hasbit(X, i)) ans += mint(2).Pow(i + n - 1);
  wt(ans);
}

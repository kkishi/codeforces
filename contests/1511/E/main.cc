#include <bits/stdc++.h>

#include "codeforces.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  V<string> g(n);
  cin >> g;
  int tot = 0;
  rep(i, n) rep(j, m) if (g[i][j] == 'o')++ tot;
  mint ans = 0;
  rep(i, n) rep(j, m) if (g[i][j] == 'o') {
    if (i + 1 < n && g[i + 1][j] == 'o') {
      ans += mint(2).Pow(tot - 2);
      if (i + 2 < n && g[i + 2][j] == 'o') {
        if (i - 1 >= 0 && g[i - 1][j] == 'o') {
          ans -= mint(2).Pow(tot - 4);
        } else {
          ans -= mint(2).Pow(tot - 3);
        }
      }
    }
    if (j + 1 < m && g[i][j + 1] == 'o') {
      ans += mint(2).Pow(tot - 2);
      if (j + 2 < m && g[i][j + 2] == 'o') {
        if (j - 1 >= 0 && g[i][j - 1] == 'o') {
          ans -= mint(2).Pow(tot - 4);
        } else {
          ans -= mint(2).Pow(tot - 3);
        }
      }
    }
  }
  wt(ans);
}

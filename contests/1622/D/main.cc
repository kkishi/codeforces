#include <bits/stdc++.h>

#include "codeforces.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, k);
  if (k == 0) {
    wt(1);
    return;
  }
  strings(s);
  V<int> v;
  v.pb(-1);
  rep(i, n) if (s[i] == '1') v.pb(i);
  v.pb(n);
  if (sz(v) - 2 < k) {
    wt(1);
    return;
  }
  mint ans = 0;
  for (int i = 0;; ++i) {
    int j = i + k + 1;
    if (j == sz(v)) break;
    int l = v[i] + 1, r = v[j];
    mint x = mint::Comb(r - l, k);
    if (j < sz(v) - 1) {
      int m = v[i + 1] + 1;
      x -= mint::Comb(r - m, k - 1);
    }
    ans += x;
  }
  wt(ans);
}

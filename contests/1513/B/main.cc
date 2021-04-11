#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int one = a[0];
  rep(i, n) one &= a[i];
  int cnt = 0;
  rep(i, n) if (!(~one & a[i]))++ cnt;
  wt(cnt * (cnt - 1) * mint::Fact(n - 2));
}

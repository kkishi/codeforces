#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> o(n);
  rep(i, n) o[a[i]] = i;
  int l = o[0];
  int r = o[0];
  int s = 0;
  mint ans = 1;
  rep(i, 1, n) {
    if (o[i] < l) {
      s += l - o[i];
      l = o[i];
    } else if (r < o[i]) {
      s += o[i] - r;
      r = o[i];
    } else {
      ans *= s;
    }
    --s;
  }
  wt(ans);
}

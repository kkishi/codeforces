#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<tuple<int, int, int, int>> ans;
  rep(i, n - 1) {
    int g = gcd(a[i], a[i + 1]);
    if (g != 1) {
      if (a[i] <= a[i + 1]) {
        ans.eb(i + 1, i + 2, a[i], a[i] + 1);
        a[i + 1] = a[i] + 1;
      } else {
        while (true) {
          ++a[i];
          bool ok = true;
          if (i > 0 && gcd(a[i - 1], a[i]) != 1) ok = false;
          if (gcd(a[i], a[i + 1]) != 1) ok = false;
          if (ok) break;
        }
        ans.eb(i + 1, i + 2, a[i], a[i + 1]);
      }
    }
  }
  rep(i, n - 1) assert(gcd(a[i], a[i + 1]) == 1);
  rep(i, n) assert(a[i] >= 1);
  dbg(a);
  wt(sz(ans));
  for (auto [a, b, c, d] : ans) wt(a, b, c, d);
}

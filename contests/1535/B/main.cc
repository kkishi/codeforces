#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> E, O;
  each(e, a)(even(e) ? E : O).pb(e);
  sort(all(O));
  V<int> b;
  each(e, E) b.pb(e);
  each(e, O) b.pb(e);
  int ans = 0;
  rep(i, n - 1) rep(j, i + 1, n) {
    if (gcd(b[i], 2 * b[j]) > 1) ++ans;
  }
  wt(ans);
}

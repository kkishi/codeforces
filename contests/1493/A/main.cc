#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
  ints(n, k);
  V<int> ans;
  rep(i, 1, n + 1) if (i != k && i * 2 >= k) ans.pb(i);
  wt(sz(ans));
  wt(ans);
}

void Main() {
  ints(t);
  rep(t) Solve();
}

#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int mini = *min_element(all(a));
  int ans = 0;
  each(e, a) if (e > mini)++ ans;
  wt(ans);
}

void Main() {
  ints(t);
  rep(t) Solve();
}

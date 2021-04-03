#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, k);
  V<int> ans;
  rep(i, 1, n + 1) if (i != k && i * 2 >= k) ans.pb(i);
  wt(sz(ans));
  wt(ans);
}

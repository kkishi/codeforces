#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 1;
  {
    int cnt = 0;
    rep(i, n) if (a[i] <= 0)++ cnt;
    chmax(ans, cnt);
  }
  sort(all(a));
  a.erase(unique(all(a)), a.end());
  auto it = lower_bound(all(a), 1);
  rep(3) {
    if (it == a.end()) break;
    int cnt = 1;
    auto jt = it;
    while (true) {
      auto kt = jt;
      while (kt != a.begin() && *jt - *kt < *it) --kt;
      if (*jt - *kt < *it) break;
      ++cnt;
      jt = kt;
    }
    chmax(ans, cnt);
    ++it;
  }
  wt(ans);
}

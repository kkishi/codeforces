#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  V<multiset<int>> sts(n + 1);
  rep(i, n) sts[a[i]].insert(b[i]);
  int ans = 0;
  rep(i, 1, n + 1) {
    auto& st = sts[i];
    rep(i) {
      if (st.empty()) break;
      auto it = prev(st.end());
      ans += *it;
      st.erase(it);
    }
  }
  wt(ans);
}

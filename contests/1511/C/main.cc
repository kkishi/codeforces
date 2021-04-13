#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  V<int> ans;
  rep(q) {
    ints(t);
    rep(i, n) if (a[i] == t) {
      ans.pb(i + 1);
      rrep(j, i) swap(a[j], a[j + 1]);
      break;
    }
  }
  wt(ans);
}

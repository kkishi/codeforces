#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  set<int> st;
  rep(i, n) st.insert(i + 1);
  V<int> A;
  each(e, a) {
    if (st.count(e)) {
      st.erase(e);
    } else {
      A.pb(e);
    }
  }
  swap(a, A);
  sort(all(a));
  V<int> r(all(st));
  rrep(i, sz(r)) {
    if ((a[i] - 1) / 2 < r[i]) {
      wt(-1);
      return;
    }
  }
  wt(sz(a));
}

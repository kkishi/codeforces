#include <bits/stdc++.h>

#include "codeforces.h"
#include "factors.h"

void Solve() {
  ints(n, k);
  int ans = 0;
  V<int> a(n);
  cin >> a;
  auto excess = [](int x) {
    V<int> ret;
    each(k, v, Factors(x)) if (!even(v)) ret.pb(k);
    return ret;
  };
  set<vector<int>> st;
  each(e, a) {
    V<int> k = excess(e);
    if (st.count(k)) {
      st.clear();
    }
    if (st.empty()) {
      ++ans;
    }
    st.insert(k);
  }
  wt(ans);
}

void Main() {
  ints(t);
  rep(t) Solve();
}

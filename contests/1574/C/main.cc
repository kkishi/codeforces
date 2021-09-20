#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  set<int> st(all(a));
  ints(m);
  int sum = accumulate(all(a), int(0));
  rep(m) {
    ints(x, y);
    auto it = st.lower_bound(x);
    int ans = big;
    if (it != st.end()) {
      chmin(ans, max(0, y - (sum - *it)));
    }
    if (it != st.begin()) {
      --it;
      chmin(ans, x - *it + max(0, y - (sum - *it)));
    }
    wt(ans);
  }
}

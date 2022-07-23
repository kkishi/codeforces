#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> b(n);
  cin >> b;
  VV<pair<int, int>> v(n);
  rep(i, n) {
    int L = (i + 1) / (b[i] + 1);
    int R = b[i] == 0 ? n : ((i + 1) / b[i]);
    v[L].eb(R, i);
  }
  set<pair<int, int>> st;
  V<int> a(n);
  rep(i, n) {
    each(x, y, v[i]) st.emplace(x, y);
    auto it = st.begin();
    a[it->second] = i + 1;
    st.erase(it);
  }
  wt(a);
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "disjoint_set.h"

void Main() {
  ints(n);
  using T = tuple<int, int, int>;
  V<T> v;
  rep(n) {
    ints(c, l, r);
    v.eb(c, l, r);
  }
  DisjointSet ds(n);
  rep(i, n) rep(j, i) {
    auto [c, l, r] = v[i];
    auto [C, L, R] = v[j];
    if (c != C && !(r < L) && !(R < l)) ds.Union(i, j);
  }
  set<int> st;
  rep(i, n) st.insert(ds.Find(i));
  wt(sz(st));
}

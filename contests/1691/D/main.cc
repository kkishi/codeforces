#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "max_segment_tree.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  V<pair<int, int>> v;
  rep(i, n) v.eb(a[i], i);
  sort(v, greater{});

  V<int> ls = a, rs = a;
  rep(i, 1, n) ls[i] += ls[i - 1];
  rrep(i, n - 1) rs[i] += rs[i + 1];
  MaxSegmentTree<int> lt(n), rt(n);
  rep(i, n) lt.Set(i, ls[i]);
  rep(i, n) rt.Set(i, rs[i]);

  set<int> st;
  st.insert(-1);
  st.insert(n);
  bool ans = true;
  each(ai, i, v) {
    auto [it, _] = st.insert(i);
    int l = *prev(it);
    int r = *next(it);
    int sum = ai;
    sum += lt.Aggregate(i, r) - ls[i];
    sum += rt.Aggregate(l + 1, i + 1) - rs[i];
    if (ai < sum) ans = false;
  }
  wt(ans);
}

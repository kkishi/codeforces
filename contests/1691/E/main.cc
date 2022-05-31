#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "disjoint_set.h"

void Main() {
  ints(n);
  using T = tuple<int, int, int, int>;
  V<T> v;
  V<int> R;
  rep(i, n) {
    ints(c, l, r);
    v.eb(l, 1, c, i);
    v.eb(r + 1, 0, c, i);
    R.eb(r);
  }
  sort(v);

  DisjointSet ds(n);
  V<set<int>> st(2);
  for (auto [_, add, c, i] : v) {
    if (add) {
      st[c].insert(i);
      if (!st[0].empty() && !st[1].empty()) {
        each(e, st) {
          while (sz(e) > 1) {
            auto it = prev(e.end());
            ds.Union(*e.begin(), *it);
            // Leave the one that extends to the right longer.
            if (R[*e.begin()] < R[*it]) {
              e.erase(e.begin());
            } else {
              e.erase(it);
            }
          }
        }
        ds.Union(*st[0].begin(), *st[1].begin());
      }
    } else {
      st[c].erase(i);
    }
  }

  set<int> ST;
  rep(i, n) ST.insert(ds.Find(i));
  wt(sz(ST));
}

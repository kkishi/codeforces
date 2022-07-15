#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "codeforces.h"

bool one(update_sum::S x) { return x.val == x.len; }
bool zero(update_sum::S x) { return x.val == 0; }

void Main() {
  int N = 200000;
  update_sum::segtree t(N + 100);
  auto add = [&](int i) {
    int j = t.max_right<one>(i);
    t.apply(i, j, 0);
    t.set(j, {1, 1});
  };
  auto sub = [&](int i) {
    int j = t.max_right<zero>(i);
    t.apply(i, j, 1);
    t.set(j, {0, 1});
  };
  ints(n, q);
  V<int> a(n);
  cin >> a;
  each(e, a) add(e);
  rep(q) {
    ints(k, l);
    --k;
    sub(a[k]);
    a[k] = l;
    add(a[k]);
    wt(t.min_left<zero>(N + 100) - 1);
  }
}

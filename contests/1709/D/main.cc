#include <bits/stdc++.h>

#include "codeforces.h"
#include "max_segment_tree.h"

void Main() {
  ints(n, m);
  V<int> a(m);
  cin >> a;
  MaxSegmentTree<int> t(m);
  rep(i, m) t.Set(i, a[i]);
  ints(q);
  rep(q) {
    ints(xs, ys, xf, yf, k);
    wt([&] {
      if (abs(xs - xf) % k) return false;
      if (abs(ys - yf) % k) return false;
      int mx = xs + (n - xs) / k * k;
      if (ys > yf) swap(ys, yf);
      return t.Aggregate(ys, yf) < mx;
    }());
  }
}

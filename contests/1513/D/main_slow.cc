#include <bits/stdc++.h>

#include "binary_search.h"
#include "codeforces_multi.h"
#include "dual_segment_tree.h"
#include "segment_tree.h"

void Main() {
  ints(n, p);
  V<int> a(n);
  cin >> a;
  SegmentTree<int> mt(
      n, [](int a, int b) { return min(a, b); }, big);
  SegmentTree<int> gt(
      n, [](int a, int b) { return gcd(a, b); }, 0);
  DualSegmentTree<int> et(
      n - 1, [](int a, int b) { return min(a, b); }, p);
  rep(i, n) {
    mt.Set(i, a[i]);
    gt.Set(i, a[i]);
  }
  rep(i, n) {
    int l = BinarySearch<int>(i, -1, [&](int x) {
      return mt.Aggregate(x, i + 1) == a[i] && gt.Aggregate(x, i + 1) == a[i];
    });
    int r = BinarySearch<int>(i + 1, n + 1, [&](int x) {
      return mt.Aggregate(i, x) == a[i] && gt.Aggregate(i, x) == a[i];
    });
    et.Update(l, r - 1, a[i]);
  }
  int ans = 0;
  rep(i, n - 1) ans += et.Get(i);
  wt(ans);
}

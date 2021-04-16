#include <bits/stdc++.h>

#include <atcoder/segtree>

#include "binary_search.h"
#include "codeforces_multi.h"
#include "dual_segment_tree.h"

using atcoder::segtree;

int opgcd(int a, int b) { return gcd(a, b); }
int egcd() { return 0; }

void Main() {
  ints(n, p);
  V<int> a(n);
  cin >> a;

  segtree<int, opgcd, egcd> gt(a);
  DualSegmentTree<int> et(
      n - 1, [](int a, int b) { return min(a, b); }, p);
  rep(i, n) {
    int l = BinarySearch<int>(i, -1,
                              [&](int x) { return gt.prod(x, i + 1) == a[i]; });
    int r = BinarySearch<int>(i + 1, n + 1,
                              [&](int x) { return gt.prod(i, x) == a[i]; });
    et.Update(l, r - 1, a[i]);
  }
  int ans = 0;
  rep(i, n - 1) ans += et.Get(i);
  wt(ans);
}

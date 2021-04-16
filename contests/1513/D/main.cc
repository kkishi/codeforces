#include <bits/stdc++.h>

#include <atcoder/segtree>

#include "codeforces_multi.h"
#include "dual_segment_tree.h"

using atcoder::segtree;

int opgcd(int a, int b) { return gcd(a, b); }
int egcd() { return 0; }

int A;
bool gf(int x) { return gcd(x, A) == A; };

void Main() {
  ints(n, p);
  V<int> a(n);
  cin >> a;

  segtree<int, opgcd, egcd> gt(a);
  DualSegmentTree<int> et(
      n - 1, [](int a, int b) { return min(a, b); }, p);
  rep(i, n) {
    A = a[i];
    int l = gt.min_left<gf>(i + 1);
    int r = gt.max_right<gf>(i);
    et.Update(l, r - 1, a[i]);
  }
  int ans = 0;
  rep(i, n - 1) ans += et.Get(i);
  wt(ans);
}

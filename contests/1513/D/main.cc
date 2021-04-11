#include <bits/stdc++.h>

#include <atcoder/segtree>

#include "codeforces_multi.h"
#include "dual_segment_tree.h"

using atcoder::segtree;

int opmin(int a, int b) { return min(a, b); }
int emin() { return big; }

int opgcd(int a, int b) { return gcd(a, b); }
int egcd() { return 0; }

int A;
bool mf(int x) { return min(x, A) == A; }
bool gf(int x) { return gcd(x, A) == A; };

void Main() {
  ints(n, p);
  V<int> a(n);
  cin >> a;

  segtree<int, opmin, emin> mt(a);
  segtree<int, opgcd, egcd> gt(a);

  DualSegmentTree<int> et(
      n - 1, [](int a, int b) { return min(a, b); }, p);

  V<tuple<int, int, int>> es;
  es.eb(0, n - 1, p);
  rep(i, n) {
    A = a[i];
    int l = max(mt.min_left<mf>(i + 1), gt.min_left<gf>(i + 1));
    int r = min(mt.max_right<mf>(i), gt.max_right<gf>(i));
    et.Update(l, r - 1, a[i]);
  }
  int ans = 0;
  rep(i, n - 1) ans += et.Get(i);
  wt(ans);
}

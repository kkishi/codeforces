#include <bits/stdc++.h>

#include <atcoder/segtree>

#include "binary_search.h"
#include "codeforces_multi.h"

using atcoder::segtree;

int opmin(int a, int b) { return min(a, b); }
int emin() { return big; }

int opgcd(int a, int b) { return gcd(a, b); }
int egcd() { return 0; }

void Main() {
  ints(n, p);
  V<int> a(n);
  cin >> a;

  segtree<int, opmin, emin> mt(a);
  segtree<int, opgcd, egcd> gt(a);

  VV<int> add(n), rem(n);
  rep(i, n) {
    int l = BinarySearch<int>(i, -1, [&](int x) {
      return mt.prod(x, i + 1) == a[i] && gt.prod(x, i + 1) == a[i];
    });
    int r = BinarySearch<int>(i + 1, n + 1, [&](int x) {
      return mt.prod(i, x) == a[i] && gt.prod(i, x) == a[i];
    });
    add[l].pb(a[i]);
    rem[r - 1].pb(a[i]);
  }
  int ans = 0;
  multiset<int> s;
  s.insert(p);
  rep(i, n - 1) {
    each(e, add[i]) s.insert(e);
    each(e, rem[i]) s.erase(s.find(e));
    ans += *s.begin();
  }
  wt(ans);
}

#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "codeforces.h"

using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b) { return std::min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return (f == ID ? x : f); }
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }

void Main() {
  ints(n, m);
  V<tuple<int, int, int>> t;
  rep(n) {
    ints(l, r, w);
    t.eb(w, l, r);
  }
  sort(all(t));

  std::vector<S> v(m, -INF);
  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

  int ans = big;
  for (auto [w, l, r] : t) {
    --l, --r;
    seg.apply(l, r, w);
    chmin(ans, w - seg.prod(0, m - 1));
  }
  wt(ans);
}

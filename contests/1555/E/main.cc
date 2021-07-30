#include <bits/stdc++.h>

#include <atcoder/lazysegtree>

#include "codeforces.h"

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b) { return std::min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

void Main() {
  ints(n, m);
  V<tuple<int, int, int>> t;
  rep(n) {
    ints(l, r, w);
    t.eb(w, l, r);
  }
  sort(all(t));

  std::vector<S> v(m);
  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

  deque<tuple<int, int, int>> ws;
  int ans = big;
  for (auto [w, l, r] : t) {
    --l, --r;
    seg.apply(l, r, 1);
    ws.eb(w, l, r);
    while (seg.prod(0, m - 1) > 0) {
      int L = get<0>(ws[0]);
      int H = get<0>(ws[sz(ws) - 1]);
      chmin(ans, H - L);
      while (!ws.empty() && get<0>(ws[0]) == L) {
        seg.apply(get<1>(ws[0]), get<2>(ws[0]), -1);
        ws.pop_front();
      }
    }
  }
  wt(ans);
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "compressor.h"
#include "disjoint_set.h"
#include "int_sqrt.h"

#undef int

void Main() {
  ints(n);
  using T = tuple<int, int, int>;
  V<T> v;
  V<i64> x;
  rep(n) {
    ints(c, l, r);
    v.eb(c, l, r);
    x.eb(l);
    x.eb(r);
  }
  Compressor c(x);
  rep(i, n) {
    get<1>(v[i]) = c(get<1>(v[i]));
    get<2>(v[i]) = c(get<2>(v[i])) + 1;
  }
  int N = sz(c.coord);
  int M = IntSqrt(N);
  // M = 1;
  vector S(N, vector(2, V<int>()));
  vector L(N, vector(2, V<int>()));
  rep(I, n) {
    auto [c, l, r] = v[I];
    int ll = div_ceil(l, M) * M;
    int rr = r / M * M;
    rep(i, l, min(ll, r)) S[i][c].eb(I);
    rep(i, max(l, rr), r) S[i][c].eb(I);
    int lll = ll / M;
    int rrr = rr / M;
    rep(i, lll, rrr) { L[i][c].eb(I); }
  }

  DisjointSet ds(n);
  auto uni = [&](const auto& v) {
    rep(i, sz(v)) {
      const auto& e = v[i];
      if (!e[0].empty() && !e[1].empty()) {
        ds.Union(e[0][0], e[1][0]);
        each(f, e) rep(j, sz(f)) ds.Union(f[0], f[j]);
      }
    }
  };
  uni(S);  // S->S
  uni(L);  // L->L
  // S->L
  rep(i, sz(S)) {
    rep(c, 2) {
      auto& s = S[i][c];
      if (s.empty()) continue;
      int I = i / M;
      auto& l = L[I][1 - c];
      if (l.empty()) continue;
      ds.Union(s[0], l[0]);
      rep(j, sz(s)) ds.Union(s[0], s[j]);
      rep(j, sz(l)) ds.Union(l[0], l[j]);
    }
  }

  set<int> st;
  rep(i, n) st.insert(ds.Find(i));
  wt(sz(st));
}

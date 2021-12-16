#include <bits/stdc++.h>

#include "codeforces_interactive.h"

void Solve() {
  ints(n);
  V<int> r1(n);
  auto next = [&](int i) { return i % n + 1; };
  auto ask = [&](int i, int j, int k) -> int {
    assert(sz(set{i, j, k}) == 3);
    wt_flush('?', i, j, k);
    ints(r);
    dbg(i, j, k, r);
    return r;
  };
  rep(i, n) {
    int a = i + 1;
    int b = next(a);
    int c = next(b);
    r1[i] = ask(a, b, c);
  }
  V<int> r2(n);
  rep(i, n - 1) if (r1[i] != r1[i + 1]) {
    int x = next(i + 1);
    int y = next(x);
    dbg(x, y);
    rep(j, n) {
      if (j + 1 == x || j + 1 == y) {
        r2[j] = -1;
      } else {
        r2[j] = ask(x, y, j + 1);
      }
    }
    break;
  }
  dbg(r2);
  V<int> is;
  V<int> cs;
  rep(i, n) {
    if (r2[i] == 0) is.pb(i);
    if (r2[i] == 1) cs.pb(i);
  }
  dbg(is, cs);
  if (sz(is) == 0) {
    assert(n == 6);
    assert(sz(cs) == 4);
    each(e, r2) if (e == -1) e = 0;
  } else {
    rep(i, n) if (r2[i] == -1) r2[i] = ask(is[0] + 1, cs[0] + 1, i + 1);
  }
  dbg(r2);
  V<int> ans;
  rep(i, n) if (r2[i] == 0) ans.eb(i + 1);
  cout << "! " << sz(ans) << " ";
  wt_flush(ans);
  dbg(ans);
}

void Main() {
  ints(t);
  rep(t) Solve();
}

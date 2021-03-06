#include <bits/stdc++.h>

#include "codeforces.h"

int DoSolve(const V<int>& a, const V<int>& b) {
  dbg(a, b);
  set<int> special;
  each(x, b) special.insert(x);
  int cnt = 0;
  each(x, a) if (special.count(x))++ cnt;

  V<pair<int, bool>> c;
  each(x, a) c.eb(x, false);
  each(x, b) c.eb(x, true);
  sort(all(c));

  int as = 0;
  deque<int> bs;
  int ans = cnt;
  for (auto [x, is_b] : c) {
    if (!is_b) {
      if (special.count(x)) --cnt;
      ++as;
    } else {
      bs.push_front(x);
      while (!bs.empty() && x - bs.back() > as - 1) {
        bs.pop_back();
      }
      chmax(ans, sz(bs) + cnt);
      dbg(x, as, sz(bs), ans);
    }
  }
  return ans;
}

void Solve() {
  ints(n, m);
  V<int> a(n), b(m);
  cin >> a >> b;
  V<int> ap, bp, an, bn;
  each(x, a)(x < 0 ? an : ap).pb(x);
  each(x, b)(x < 0 ? bn : bp).pb(x);
  int po = DoSolve(ap, bp);
  reverse(all(an));
  each(x, an) x = -x;
  reverse(all(bn));
  each(x, bn) x = -x;
  int ne = DoSolve(an, bn);
  dbg(po, ne);
  wt(po + ne);
}

void Main() {
  ints(t);
  rep(t) Solve();
}

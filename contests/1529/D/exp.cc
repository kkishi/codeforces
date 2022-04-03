#include <bits/stdc++.h>

#include "codeforces.h"

struct S {
  int l, r;
  int len() const { return r - l; }
  bool contains(S& s) const { return l < s.l && s.r < r; }
};

int Naive(int x) {
  int ans = 0;
  V<bool> used(2 * x);
  V<S> ps;
  Fix([&](auto rec, int depth, int start) -> void {
    if (depth == x) {
      ++ans;
      return;
    }
    rep(i, start, sz(used)) if (!used[i]) {
      used[i] = true;
      rep(j, i + 1, sz(used)) if (!used[j]) {
        used[j] = true;
        ps.pb({i, j});
        S a = ps.back();
        bool ok2 = true;
        rep(k, sz(ps) - 1) {
          bool ok = false;
          S b = ps[k];
          if (a.len() == b.len()) ok = true;
          if (a.contains(b) || b.contains(a)) ok = true;
          if (!ok) ok2 = false;
        }
        if (ok2) {
          rec(depth + 1, i + 1);
        }
        ps.pop_back();
        used[j] = false;
      }
      used[i] = false;
      return;
    }
  })(0, 0);
  return ans;
}

void Main() {
  ints(n);
  rep(i, 1, 20) dbg(i, Naive(i));
  // wt(Naive(n));
}

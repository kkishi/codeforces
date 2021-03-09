#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n1, n2, n3, n4);
  V<int> a(n1), b(n2), c(n3), d(n4);
  cin >> a >> b >> c >> d;

  auto f = [](V<int>& l, V<int>& r) {
    ints(m);
    set<array<int, 2>> ng;
    rep(m) {
      ints(li, ri);
      ng.insert({li - 1, ri - 1});
    }
    rep(i, sz(r)) {
      int x = big;
      rep(j, sz(l)) if (ng.count({j, i}) == 0) { chmin(x, l[j]); }
      if (x == big) {
        r[i] = big;
      } else {
        r[i] += x;
      }
    }
  };
  f(a, b);
  f(b, c);
  f(c, d);
  int ans = *min_element(all(d));
  if (ans == big) ans = -1;
  wt(ans);
}

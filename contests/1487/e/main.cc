#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n1, n2, n3, n4);
  V<int> a(n1), b(n2), c(n3), d(n4);
  cin >> a >> b >> c >> d;

  auto f = [](V<int>& l, V<int>& r) {
    V<int> idx(sz(l));
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) { return l[i] < l[j]; });
    V<int> ridx(sz(l));
    rep(i, sz(l)) ridx[idx[i]] = i;

    {
      V<int> sl(sz(l));
      rep(i, sz(l)) sl[i] = l[idx[i]];
      swap(l, sl);
    }

    ints(m);
    V<pair<int, int>> lr(m);
    cin >> lr;
    each(li, ri, lr)-- li, --ri;
    each(li, _, lr) li = ridx[li];
    sort(all(lr));

    VV<int> ng(sz(r));
    each(e, ng) e.pb(-1);
    each(li, ri, lr) ng[ri].pb(li);
    each(e, ng) e.pb(sz(l));

    rep(i, sz(r)) {
      int x = big;
      const V<int>& n = ng[i];
      rep(j, 1, sz(n)) {
        if (n[j] > n[j - 1] + 1) {
          x = l[n[j - 1] + 1];
          break;
        }
      }
      r[i] = min(big, r[i] + x);
    }
  };
  f(a, b);
  f(b, c);
  f(c, d);
  int ans = *min_element(all(d));
  if (ans == big) ans = -1;
  wt(ans);
}

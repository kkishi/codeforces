#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> A = a;
  V<int> p;
  int x = 0;
  while (sz(a) >= 1) {
    if ((a.back() ^ x) == 1) {
      wt("NO");
      return;
    }
    if (sz(a) == 1) {
      p.eb(0);
      a.pop_back();
    } else {
      int len = sz(a);
      if ((a[len - 2] ^ x) == 1) {
        p.eb(len - 1);
        a.pop_back();
        x ^= 1;
      } else {
        p.eb(len - 2);
        x ^= 1;
        rep(2) a.pop_back();
        a.eb(x);
      }
    }
  }
  reverse(p);
  wt("YES");
  wt(p);
#ifdef DEBUG
  V<int> b;
  each(e, p) {
    V<int> nb;
    rep(i, e) nb.eb(1 - b[i]);
    nb.eb(0);
    rep(i, e, sz(b)) nb.eb(b[i]);
    swap(b, nb);
  }
  assert(A == b);
#endif
}

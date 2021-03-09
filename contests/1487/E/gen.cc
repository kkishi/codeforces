#include <bits/stdc++.h>

#include "codeforces.h"
#include "rand.h"

void Main() {
  Rand r;
  int n = 4, m = 8;
  rep(4) wt(n);
  rep(4) rep(n) wt(r.Int(1, 10));
  rep(4) {
    wt(m);
    set<array<int, 2>> s;
    rep(m) {
      while (true) {
        int i = r.Int(1, n);
        int j = r.Int(1, n);
        if (!s.insert({i, j}).second) continue;
        wt(i, j);
        break;
      }
    }
  }
}

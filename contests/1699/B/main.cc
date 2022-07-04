#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, m);
  vector a(n, vector(m, int(0)));
  rep(i, n / 2) rep(j, m / 2) {
    rep(I, 2) rep(J, 2) {
      a[i * 2 + I][j * 2 + J] = even(i) ^ even(j) ^ even(I) ^ even(J);
    }
  }
  each(e, a) wt(e);
}

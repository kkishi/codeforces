#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> l(n);
  cin >> l;
  rep(i, n + 1) {
    int liars = 0;
    each(e, l) if (e > i)++ liars;
    if (liars == i) {
      wt(i);
      return;
    }
  }
  wt(-1);
}

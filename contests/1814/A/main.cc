#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, k);
  rep(i, 3) {
    int d = n - k * i;
    if (d >= 0 && even(d)) {
      wt(true);
      return;
    }
  }
  wt(false);
}

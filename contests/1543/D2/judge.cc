#include <bits/stdc++.h>

#include "codeforces_interactive.h"

void Main() {
  int t = 1;
  wt(t);
  rep(t) {
    int n = 10, k = 2;
    wt(n, k);
    int x = 2;
    while (true) {
      ints(y);
      if (x == y) {
        wt_flush(1);
        return;
      }
      wt_flush(0);
      x ^= y;
    }
  }
}

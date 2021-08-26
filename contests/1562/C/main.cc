#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  strings(s);
  each(e, s) e -= '0';
  int l = n / 2;
  rep(i, n) if (s[i] == 0) {
    if (i + l < n) {
      // XXX, 0XXX
      wt(i + 1, i + l + 1, i + 2, i + l + 1);
    } else {
      // XXX, XXX0
      wt(i - l + 1, i + 1, i - l + 1, i);
    }
    return;
  }
  // 111, X11
  wt(1, l, 2, l + 1);
}

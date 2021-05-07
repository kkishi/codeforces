#include <bits/stdc++.h>

#include "codeforces_interactive.h"

void Main() {
  int t = 1;
  wt_flush(t);
  V<int> a = {5, 4, 3, 2, 1};
  int n = sz(a);
  wt_flush(n);
  while (true) {
    rd(char, k);
    if (k == '!') {
      V<int> b(n);
      cin >> b;
      assert(b == a);
      return;
    }
    ints(t, i, j, x);
    --i, --j;
    if (t == 1) {
      wt_flush(max(min(x, a[i]), min(x + 1, a[j])));
    } else {
      wt_flush(min(max(x, a[i]), max(x + 1, a[j])));
    }
  }
}

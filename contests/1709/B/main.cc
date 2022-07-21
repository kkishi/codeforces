#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  V<int> b(n);
  rep(i, n - 1) b[i + 1] = b[i] + max(0, a[i] - a[i + 1]);
  V<int> c(n);
  rrep(i, n - 1) c[i] = c[i + 1] + max(0, a[i + 1] - a[i]);
  rep(m) {
    ints(s, t);
    --s, --t;
    if (s < t) {
      wt(b[t] - b[s]);
    } else {
      wt(c[t] - c[s]);
    }
  }
}

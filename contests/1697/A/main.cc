#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  int e = m;
  rep(i, n) {
    if (e < a[i]) {
      int x = a[i] - e;
      e += x;
      ans += x;
    }
    e -= a[i];
  }
  wt(ans);
}

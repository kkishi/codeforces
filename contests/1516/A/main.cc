#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  int s = 0;
  rep(i, n) {
    int x = min(a[i], (k - s));
    a[i] -= x;
    s += x;
  }
  a.back() += s;
  wt(a);
}

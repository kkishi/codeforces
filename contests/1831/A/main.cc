#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> b(n);
  rep(i, n) b[i] = n + 1 - a[i];
  wt(b);
}

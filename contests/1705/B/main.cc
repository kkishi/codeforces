#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int p = 0;
  while (p < n && a[p] == 0) ++p;
  int x = 0;
  rep(i, p, n) if (a[i] == 0)++ x;
  wt(x + accumulate(a) - (a.back() == 0 ? 1 : a.back()));
}

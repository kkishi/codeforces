#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int g = 0;
  for (int i = 0, j = n - 1; i < j; ++i, --j) {
    g = gcd(g, abs(a[i] - a[j]));
  }
  wt(g);
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int sum = accumulate(all(a), int(0));
  int ny = sum % n;
  int nx = n - ny;
  wt(nx * ny);
}

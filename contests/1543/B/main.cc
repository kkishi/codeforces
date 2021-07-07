#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int sum = accumulate(all(a), int(0));
  int x = sum / n;
  int y = x + 1;
  int ny = sum % n;
  int nx = n - ny;
  assert(x * nx + y * ny == sum);
  int ans = nx * ny;
  wt(ans);
}

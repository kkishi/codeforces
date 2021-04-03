#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, k1, k2);
  ints(w, b);
  auto f = [](int x, int y, int z) {
    int m = min(x, y);
    return m + (x - m) / 2 + (y - m) / 2 >= z;
  };
  wt(f(k1, k2, w) && f(n - k1, n - k2, b));
}

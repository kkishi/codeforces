#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, k);
  int c = 1;
  int t = 0;
  while (c < n && c < k) {
    c = min(c * 2, n);
    ++t;
  }
  wt(t + div_ceil(n - c, k));
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, k);
  --k;
  if (even(n)) {
    wt(k % n + 1);
    return;
  }
  int d = (n - 1) / 2;
  int x = k / d;
  wt((k + x) % n + 1);
}

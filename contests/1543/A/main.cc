#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(a, b);
  if (a > b) swap(a, b);
  if (a == b) {
    wt(0, 0);
    return;
  }
  int x = b - a;
  int y = a % x == 0 ? 0 : min(x - a % x, a % x);
  wt(x, y);
}

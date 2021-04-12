#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> r(n);
  cin >> r;
  int up = 0;
  each(e, r) if (e == 1 || e == 3)++ up;
  wt(up);
}

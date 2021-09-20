#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(a, b, c, m);
  int x = max({a, b, c});
  int y = a + b + c - x;
  wt(x - y - 1 <= m && m <= a + b + c - 3);
}

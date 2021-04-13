#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(a, b, c);
  int t = 1;
  rep(c - 1) t *= 10;
  int x = t;
  while (sz(to_string(x)) < a) x *= 3;
  int y = t;
  while (sz(to_string(y)) < b) y *= 7;
  wt(x, y);
}

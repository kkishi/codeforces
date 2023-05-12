#include <bits/stdc++.h>

#include "codeforces.h"
#include "rand.h"

void Main() {
  Rand r;
  int n = 100;
  int m = 998244353;
  int a1 = r.Int(0, m - 1);
  int x = r.Int(0, m - 1);
  int y = r.Int(0, m - 1);
  int k = r.Int(1, 5);
  wt(n, a1, x, y, m, k);
}

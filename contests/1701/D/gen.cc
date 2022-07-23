#include <bits/stdc++.h>

#include "codeforces.h"
#include "rand.h"

void Main() {
  int n = 5;
  wt(n);
  Rand r;
  V<int> a = r.Permutation(n);
  V<int> b;
  rep(i, n) b.pb((i + 1) / a[i]);
  wt(b);
}

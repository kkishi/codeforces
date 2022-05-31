#include <bits/stdc++.h>

#include "codeforces.h"
#include "rand.h"

void Main() {
  int t = 1;
  wt(t);
  int n = 5;
  wt(n);
  Rand r;
  rep(n) {
    int L = r.Int(1, 5);
    int R = r.Int(1, 5);
    if (L > R) swap(L, R);
    wt(r.Int(0, 1), L, R);
  }
}

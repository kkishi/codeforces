#include <bits/stdc++.h>

#include "codeforces.h"
#include "rand.h"

void Main() {
  int t = 1;
  wt(t);
  int n = 5;
  Rand r;
  int k = r.Int(0, 10);
  wt(n, k);
  string s;
  rep(n) s += (char)r.Int('0', '1');
  wt(s);
}

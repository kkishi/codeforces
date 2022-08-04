#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  wt(n);
  V<int> a(n);
  rep(i, n) a[i] = i + 1;
  wt(a);
  swap(a[0], a.back());
  wt(a);
  rep(i, n - 2) {
    swap(a[i], a[i + 1]);
    wt(a);
  }
}

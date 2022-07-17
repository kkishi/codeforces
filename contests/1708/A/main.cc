#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  wt([] {
    ints(n);
    V<int> a(n);
    cin >> a;
    rep(i, 1, n) if (a[i] % a[0]) return false;
    return true;
  }());
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  wt([]() {
    ints(n, x);
    V<int> h(n * 2);
    cin >> h;
    sort(h);
    rep(i, n) if (h[i] > h[i + n] - x) return false;
    return true;
  }());
}

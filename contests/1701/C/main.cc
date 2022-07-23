#include <bits/stdc++.h>

#include "binary_search.h"
#include "codeforces_multi.h"

void Main() {
  ints(n, m);
  V<int> a(m);
  cin >> a;
  V<int> h(n);
  each(e, a)++ h[e - 1];
  wt(BinarySearch<int>(m * 2, 0, [&](int x) {
    int task = 0;
    int worker = 0;
    rep(i, n) {
      task += max(0, h[i] - x);
      worker += max(0, x - h[i]) / 2;
    }
    return task <= worker;
  }));
}

#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n, q);
  V<int> p(n);
  cin >> p;
  sort(p);
  V<int> s = p;
  rep(i, 1, n) s[i] += s[i - 1];
  rep(q) {
    ints(x, y);
    int z = n - x;
    wt(s[z + y - 1] - (z == 0 ? 0 : s[z - 1]));
  }
}

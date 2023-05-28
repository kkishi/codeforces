#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  int ans = 0;
  rep(i, n) rep(j, i + 1, n) {
    if (a[i] * a[j] == b[i] + b[j]) ++ans;
  }
  wt(ans);
}

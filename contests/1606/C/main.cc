#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  V<int> t(10);
  t[0] = 1;
  rep(i, 1, sz(t)) t[i] = t[i - 1] * 10;
  rep(i, n - 1) {
    int used = 0;
    rep(j, 1, i + 1) used += t[a[j] - a[j - 1]] - 1;
    int need = t[a[i + 1] - a[i]] - 1;
    if (used + need > k) {
      int ans = (k - used + 1) * t[a[i]];
      ans += t[a[i]] - 1;
      wt(ans);
      return;
    }
  }
  int used = 0;
  rep(i, n - 1) used += t[a[i + 1] - a[i]] - 1;
  int A = a.back();
  int ans = (k - used + 1) * t[A];
  ans += t[A] - 1;
  wt(ans);
}

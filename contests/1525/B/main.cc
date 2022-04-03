#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  if (a[0] == n) {
    sort(a.begin(), a.end() - 1);
    ++ans;
  }
  if (a.back() == 1) {
    sort(a.begin() + 1, a.end());
    ++ans;
  }
  if (a[0] != 1) {
    sort(a.begin(), a.end() - 1);
    ++ans;
  }
  if (a.back() != n) {
    sort(a.begin() + 1, a.end());
    ++ans;
  }
  rep(i, n) if (a[i] != i + 1) {
    ++ans;
    break;
  }
  dbg(a);
  wt(ans);
}

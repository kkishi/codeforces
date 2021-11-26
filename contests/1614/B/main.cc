#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<pair<int, int>> v;
  rep(i, n) v.eb(a[i], i);
  sort(all(v), greater{});
  V<int> ans(n);
  int x = 1, y = 0;
  int sum = 0;
  each(ai, i, v) {
    ans[i] = x * (y == 0 ? 1 : -1);
    sum += x * 2 * ai;
    if (y == 0) {
      y = 1;
    } else {
      y = 0;
      ++x;
    }
  }
  wt(sum);
  cout << 0 << " ";
  wt(ans);
}

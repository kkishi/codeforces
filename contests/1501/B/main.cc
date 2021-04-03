#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> stk;
  rep(i, n) {
    stk.pb(i);
    int cnt = 0;
    while (!stk.empty() && (i - stk.back()) < a[i]) {
      stk.pop_back();
      ++cnt;
    }
  }
  V<int> ans(n, 1);
  each(e, stk) ans[e] = 0;
  wt(ans);
}

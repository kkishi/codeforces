#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> ans;
  int l = 0;
  rep(i, n) {
    int x = even(i) ? 3 : 5;
    int y = div_ceil(l + 1, x);
    l = y * x;
    ans.pb(l);
  }
  wt(ans);
}

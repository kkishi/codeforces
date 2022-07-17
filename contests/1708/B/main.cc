#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, l, r);
  V<int> ans;
  rrep(i, 1, n + 1) {
    int j = div_ceil(l, i) * i;
    if (j > r) {
      wt(false);
      return;
    }
    ans.pb(j);
  }
  wt(true);
  reverse(ans);
  wt(ans);
}

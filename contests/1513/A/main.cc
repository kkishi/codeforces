#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, k);
  if (n < k * 2 + 1) {
    wt(-1);
    return;
  }
  V<int> ans(n);
  rep(i, n) ans[i] = i;
  rep(i, k + 1) ans[i * 2] = i;
  rep(i, k) ans[i * 2 + 1] = k + 1 + i;
  each(e, ans)++ e;
  wt(ans);
}

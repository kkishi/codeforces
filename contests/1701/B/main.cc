#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> ans;
  V<bool> used(n + 1);
  rep(i, 1, n + 1) if (!used[i]) {
    for (int j = i; j <= n; j *= 2) {
      ans.pb(j);
      used[j] = true;
    }
  }
  wt(2);
  wt(ans);
}

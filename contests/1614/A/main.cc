#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, l, r, k);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  int ans = 0;
  each(e, a) if (l <= e && e <= min(r, k)) {
    k -= e;
    ++ans;
  }
  wt(ans);
}

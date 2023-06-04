#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, k);
  int l = 0, r = n - 1;
  int ans = 2;
  while (true) {
    l += k;
    if (l >= r) break;
    ++ans;
    r -= k;
    if (l >= r) break;
    ++ans;
  }
  wt(ans);
}

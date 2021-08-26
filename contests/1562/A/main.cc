#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(l, r);
  int ans = (r - 1) / 2;
  int x = r / 2 + 1;
  if (l <= x) {
    wt(ans);
  } else {
    wt(r - l);
  }
}

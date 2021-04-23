#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  if (n % 2050 != 0) {
    wt(-1);
    return;
  }
  int x = n / 2050;
  int ans = 0;
  while (x) {
    ans += x % 10;
    x /= 10;
  }
  wt(ans);
}

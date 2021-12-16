#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  if (even(n)) {
    wt(n / 2 - 1, n / 2, 1);
    return;
  } else {
    for (int i = 3;; ++i) {
      int j = n - 1 - i;
      if (gcd(i, j) == 1) {
        wt(i, j, 1);
        return;
      }
    }
  }
}

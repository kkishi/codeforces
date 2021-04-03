#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  while (true) {
    int s = 0;
    int m = n;
    while (m) {
      s += m % 10;
      m /= 10;
    }
    int g = gcd(s, n);
    if (g > 1) {
      wt(n);
      return;
    }
    ++n;
  }
}

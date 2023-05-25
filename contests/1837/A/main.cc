#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(x, k);
  if (x % k != 0) {
    wt(1);
    wt(x);
  } else {
    wt(2);
    wt(x - 1, 1);
  }
}

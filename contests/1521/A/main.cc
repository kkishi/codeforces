#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(a, b);
  if (b == 1) {
    wt("NO");
    return;
  }
  wt("YES");
  if (b == 2) {
    wt(a, a * 3, a * 4);
  } else {
    wt(a, a * (b - 1), a * b);
  }
}

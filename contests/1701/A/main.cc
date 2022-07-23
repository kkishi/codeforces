#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  V<int> a(4);
  cin >> a;
  if (accumulate(a) == 0) {
    wt(0);
  } else if (accumulate(a) == 4) {
    wt(2);
  } else {
    wt(1);
  }
}

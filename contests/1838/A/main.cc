#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  if (min(a) >= 0) {
    wt(max(a));
  } else {
    wt(min(a));
  }
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  wt([] {
    V<int> l(3);
    cin >> l;
    rep(i, 3) {
      int a = l[i];
      int b = l[(i + 1) % 3];
      int c = l[(i + 2) % 3];
      if (a == b + c) {
        return true;
      }
      if (b == c && even(a)) {
        return true;
      }
    }
    return false;
  }());
}

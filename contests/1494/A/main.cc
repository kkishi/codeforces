#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  wt([] {
    strings(s);
    each(x, s) x -= 'A';
    rep(bits, 1 << 3) {
      bool ok = true;
      int x = 0;
      each(c, s) {
        if (hasbit(bits, c)) {
          ++x;
        } else {
          --x;
        }
        if (x < 0) ok = false;
      }
      if (x != 0) ok = false;
      if (ok) return true;
    }
    return false;
  }());
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  strings(a, b);
  V<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + (a[i] == '1');
  int flip = 0;
  rrep(i, n) {
    if ((a[i] ^ flip) != b[i]) {
      if (s[i + 1] * 2 != (i + 1)) {
        wt("NO");
        return;
      }
      flip ^= 1;
    }
  }
  wt("YES");
}

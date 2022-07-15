#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, c, q);
  strings(s);
  rep(c) {
    ints(l, r);
    --l;
    s += s.substr(l, r - l);
  }
  rep(q) {
    ints(k);
    --k;
    wt(s[k]);
  }
}

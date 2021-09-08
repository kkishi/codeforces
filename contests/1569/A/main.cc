#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  strings(s);
  rep(i, n - 1) if (s[i] != s[i + 1]) {
    wt(i + 1, i + 2);
    return;
  }
  wt(-1, -1);
}

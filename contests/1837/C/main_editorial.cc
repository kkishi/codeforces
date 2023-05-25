#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  strings(s);
  rep(i, sz(s)) if (s[i] == '?') {
    if (i == 0 || s[i - 1] == '0') {
      s[i] = '0';
    } else {
      s[i] = '1';
    }
  }
  wt(s);
}

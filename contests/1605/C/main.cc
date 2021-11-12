#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  strings(s);
  rep(i, n - 1) if (s[i] == 'a' && s[i + 1] == 'a') {
    wt(2);
    return;
  }
  rep(i, n - 2) if (s[i] == 'a' && s[i + 2] == 'a') {
    wt(3);
    return;
  }
  rep(i, n - 3) if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 1] != s[i + 2]) {
    wt(4);
    return;
  }
  rep(i, n - 6) if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 6] == 'a' &&
                    s[i + 1] == s[i + 2] && s[i + 4] == s[i + 5] &&
                    s[i + 1] != s[i + 4]) {
    wt(7);
    return;
  }
  wt(-1);
}

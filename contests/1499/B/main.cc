#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  wt([] {
    strings(s);
    each(e, s) e -= '0';
    int n = sz(s);

    for (int i = 0; i <= n; ++i) {
      if (i - 1 >= 0 && s[i - 1] != 0) continue;
      if (i < n && s[i] != 1) continue;
      bool ok = true;
      for (int j = 0; j + 1 <= i - 1; ++j) {
        if (s[j] == 1 && s[j + 1] == 1) ok = false;
      }
      for (int j = i + 1; j + 1 < n; ++j) {
        if (s[j] == 0 && s[j + 1] == 0) ok = false;
      }
      if (ok) return true;
    }
    return false;
  }());
}

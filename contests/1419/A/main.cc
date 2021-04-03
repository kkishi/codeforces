#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  strings(s);
  if (n & 1) {
    bool has_odd = false;
    for (int i = 0; i < n; i += 2)
      if ((s[i] - '0') & 1) has_odd = true;
    wt(has_odd ? 1 : 2);
  } else {
    bool has_even = false;
    for (int i = 1; i < n; i += 2)
      if ((s[i] - '0') % 2 == 0) has_even = true;
    wt(has_even ? 2 : 1);
  }
}

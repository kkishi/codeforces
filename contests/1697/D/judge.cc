#include <bits/stdc++.h>

#include "binary_search.h"
#include "codeforces_interactive.h"

void Main() {
  string s = "abbaacccab";
  wt(sz(s));
  while (true) {
    rd(char, t);
    if (t == '?') {
      ints(k);
      if (k == 1) {
        ints(i);
        wt_flush(s[i - 1]);
      } else {
        ints(i, j);
        wt_flush(sz(set(s.begin() + i - 1, s.begin() + j)));
      }
    } else {
      strings(t);
      assert(s == t);
      break;
    }
  }
}

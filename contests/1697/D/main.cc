#include <bits/stdc++.h>

#include "binary_search.h"
#include "codeforces_interactive.h"

void Main() {
  ints(n);
  int prev = 0;
  string s;
  map<char, int> last;
  rep(i, n) {
    wt_flush("?", 2, 1, i + 1);
    ints(x);
    if (x > prev) {
      wt_flush("?", 1, i + 1);
      rd(char, c);
      s += c;
      last[c] = i;
    } else {
      V<int> idx;
      each(_, e, last) idx.eb(e);
      sort(idx);
      int x = BinarySearch<int>(0, sz(idx), [&](int x) {
        wt_flush("?", 2, idx[x] + 1, i + 1);
        ints(y);
        return sz(idx) - x == y;
      });
      s += s[idx[x]];
      last[s[idx[x]]] = i;
    }
    prev = x;
  }
  wt_flush("!", s);
}

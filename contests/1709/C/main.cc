#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  wt([] {
    strings(s);
    int n = sz(s);
    int o = 0, c = 0;
    V<int> q;
    rep(i, n) {
      char e = s[i];
      if (e == '(') ++o;
      if (e == ')') ++c;
      if (e == '?') q.eb(i);
    }
    V<int> Q;
    while (sz(q) > (n / 2 - o)) {
      Q.eb(q.back());
      q.pop_back();
    }
    if (q.empty() || Q.empty()) return true;
    each(e, q) s[e] = '(';
    each(e, Q) s[e] = ')';
    swap(s[q.back()], s[Q.back()]);
    int x = 0;
    each(e, s) {
      if (e == '(') {
        ++x;
      } else if (e == ')') {
        if (x == 0) return true;
        --x;
      }
    }
    return false;
  }());
}

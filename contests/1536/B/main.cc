#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  strings(s);
  set<string> st;
  rep(i, n) rep(j, 1, n - i + 1) st.insert(s.substr(i, j));
  VV<string> cand(6);
  cand[0] = {""};
  rep(i, 5) {
    each(e, cand[i]) rep(j, 26) {
      string t = e + (char)('a' + j);
      if (!st.count(t)) {
        wt(t);
        return;
      }
      cand[i + 1].pb(t);
    }
  }
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  [] {
    ints(n);
    V<int> s(n);
    cin >> s;
    map<int, int> m;
    map<int, V<int>> mi;
    rep(i, n) {
      ++m[s[i]];
      mi[s[i]].push_back(i);
    }
    each(_, e, m) if (e == 1) {
      wt(-1);
      return;
    }
    V<int> ans(n);
    each(_, v, mi) rep(i, sz(v)) ans[v[i]] = v[(i + 1) % sz(v)] + 1;
    wt(ans);
  }();
}

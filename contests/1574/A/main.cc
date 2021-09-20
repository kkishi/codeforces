#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  rep(i, 1, n + 1) {
    string ans;
    rep(j, i) ans += '(';
    rep(j, i) ans += ')';
    rep(j, i, n) ans += "()";
    wt(ans);
  }
}

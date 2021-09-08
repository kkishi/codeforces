#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  strings(s);
  V<int> two;
  rep(i, n) if (s[i] == '2') two.pb(i);
  if (sz(two) == 1 || sz(two) == 2) {
    wt("NO");
    return;
  }
  wt("YES");
  V<string> ans(n, string(n, '='));
  rep(i, sz(two)) {
    int I = two[i];
    int J = two[(i + 1) % sz(two)];
    ans[I][J] = '+';
    ans[J][I] = '-';
  }
  rep(i, n) ans[i][i] = 'X';
  each(e, ans) wt(e);
}

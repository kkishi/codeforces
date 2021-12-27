#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> p(n);
  cin >> p;
  strings(s);
  V<tuple<int, int, int>> v;
  rep(i, n) v.eb(s[i] - '0', p[i], i);
  sort(all(v));
  V<int> ans(n);
  rep(i, n) ans[get<2>(v[i])] = i + 1;
  wt(ans);
}

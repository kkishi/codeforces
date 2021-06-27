#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  strings(s);
  V<int> ans(n);
  int d = 0, k = 0;
  map<pair<int, int>, int> cnt;
  rep(i, n) {
    ++(s[i] == 'D' ? d : k);
    pair<int, int> p;
    if (d == 0) {
      p = {0, 1};
    } else if (k == 0) {
      p = {1, 0};
    } else {
      int g = gcd(d, k);
      p = {d / g, k / g};
    }
    ++cnt[p];
    ans[i] = cnt[p];
  }
  wt(ans);
}

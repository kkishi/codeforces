#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  if (*min_element(all(a)) >= 0) {
    wt("YES");
    V<int> a(201);
    rep(i, 201) a[i] = i;
    wt(sz(a));
    wt(a);
  } else {
    wt("NO");
  }
}

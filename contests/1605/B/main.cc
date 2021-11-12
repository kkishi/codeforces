#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  strings(s);
  VV<int> ans;
  while (true) {
    V<int> L, R;
    int l = 0, r = n - 1;
    while (true) {
      while (l < n && s[l] == '0') ++l;
      while (r >= 0 && s[r] == '1') --r;
      if (l >= r) break;
      swap(s[l], s[r]);
      L.pb(l + 1);
      R.pb(r + 1);
      ++l;
      --r;
    }
    rrep(i, sz(R)) L.pb(R[i]);
    if (sz(L) == 0) break;
    ans.pb(L);
  }
  wt(sz(ans));
  each(e, ans) {
    cout << sz(e) << " ";
    wt(e);
  }
}

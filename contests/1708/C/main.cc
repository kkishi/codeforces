#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  int Q = 0;
  string ans;
  rrep(i, n) {
    if (Q < q) {
      if (Q < a[i]) {
        ++Q;
      }
      ans += '1';
    } else {
      ans += (char)('0' + (Q >= a[i]));
    }
  }
  reverse(ans);
  wt(ans);
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, k);
  strings(s);
  reverse(s);
  if (s[0] == '0') {
    rep(i, n) if (s[i] == '1' && i <= k) {
      rrep(j, i) swap(s[j], s[j + 1]);
      k -= i;
      break;
    }
  }
  reverse(s);
  if (s[0] == '0') {
    rep(i, n - 1) if (s[i] == '1' && i <= k) {
      rrep(j, i) swap(s[j], s[j + 1]);
      k -= i;
      break;
    }
  }
  int ans = 0;
  rep(i, n - 1) ans += 10 * (s[i] == '1') + (s[i + 1] == '1');
  wt(ans);
}

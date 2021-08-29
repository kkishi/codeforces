#include <bits/stdc++.h>

#include <atcoder/modint>

#include "codeforces.h"
#include "quotients.h"

using mint = atcoder::modint;

ostream& operator<<(ostream& os, const mint& m) {
  os << m.val();
  return os;
}

void Main() {
  ints(n, m);
  mint::set_mod(m);
  vector dp(n + 1, mint(0));
  dp[n] = 1;
  vector sdp(n + 2, mint(0));
  rrep(i, 1, n + 1) {
    dp[i] += sdp[i + 1];
    each(q, c, Quotients(i)) {
      if (q == i) continue;
      dp[q] += dp[i] * c;
    }
    sdp[i] = sdp[i + 1] + dp[i];
  }
  wt(dp[1]);
}

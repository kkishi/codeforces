#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(k);
  strings(s);
  ints(q);
  V<int> dp(1 << (k + 1), -1);
  int M = (1 << k) - 2;
  auto rec = [&](auto rec, int i) -> int {
    if (dp[i] != -1) return dp[i];
    if (i > M) {
      dp[i] = 1;
      return dp[i];
    }
    dp[i] = 0;
    char c = s[M - i];
    int l = i * 2 + 2;
    int L = rec(rec, l);
    if (c == '0' || c == '?') dp[i] += L;
    int r = i * 2 + 1;
    int R = rec(rec, r);
    if (c == '1' || c == '?') dp[i] += R;
    return dp[i];
  };
  rec(rec, 0);
  rep(q) {
    ints(p);
    rd(char, c);
    --p;

    int diff = 0;
    int i = M - p;
    diff -= dp[i];

    int l = i * 2 + 2;
    if (c == '0' || c == '?') diff += dp[l];
    int r = i * 2 + 1;
    if (c == '1' || c == '?') diff += dp[r];

    int I = i;
    while (true) {
      dp[I] += diff;
      if (I == 0) break;
      int P = (I - 1) / 2;
      char c = s[M - P];
      if (c == '0' && !even(I) || c == '1' && even(I)) {
        break;
      }
      I = P;
    }
    wt(dp[0]);

    s[p] = c;
  }
}

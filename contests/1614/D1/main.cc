#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  const int N = *max_element(all(a));
  V<int> cnt(N + 1);
  each(e, a)++ cnt[e];
  rep(i, 1, N + 1) {
    for (int j = i * 2; j <= N; j += i) {
      cnt[i] += cnt[j];
    }
  }
  V<int> dp(N + 1);
  rep(i, N + 1) dp[i] = n + (i - 1) * cnt[i];
  rrep(i, 1, N + 1) {
    for (int j = i * 2; j <= N; j += i) {
      chmax(dp[i], dp[j] + (i - 1) * (cnt[i] - cnt[j]));
    }
  }
  wt(*max_element(all(dp)));
}

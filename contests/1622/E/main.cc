#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n, m);
  V<int> x(n);
  cin >> x;
  V<string> s(n);
  cin >> s;
  int ma = -big;
  V<int> ans;
  rep(higher, 1 << n) {
    V<pair<int, int>> e(m);
    rep(i, m) {
      e[i].second = i;
      rep(j, n) if (hasbit(higher, j) == (s[j][i] == '1'))++ e[i].first;
    }
    sort(all(e));
    V<int> score(m);
    rep(i, m) score[e[i].second] = i + 1;
    int sum = 0;
    rep(i, n) {
      int y = 0;
      rep(j, m) if (s[i][j] == '1') y += score[j];
      sum += abs(x[i] - y);
    }
    if (chmax(ma, sum)) {
      swap(ans, score);
    }
  }
  wt(ans);
}

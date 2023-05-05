#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  V<int> b(n);
  cin >> b;
  using P = pair<int, int>;
  int ans = 0;
  multiset<P> right;
  rep(i, 2, n) right.emplace(b[i] - i, i);
  set<int> left;
  rep(i, 1, n - 1) {
    left.emplace(b[i - 1] + i - 1);
    int L = *prev(left.end()) - i;
    int R = prev(right.end())->first + i;
    chmax(ans, L + R + b[i]);
    right.erase({b[i + 1] - (i + 1), i + 1});
  }
  wt(ans);
}

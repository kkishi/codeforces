#include <bits/stdc++.h>

#include "codeforces.h"

using Event = tuple<int, int, int>;

void Main() {
  ints(n);
  V<pair<int, int>> v(n);
  cin >> v;
  sort(all(v));
  V<int> a(n), c(n);
  rep(i, n) tie(a[i], c[i]) = v[i];

  int max_a = *max_element(all(a));
  int sum_c = accumulate(all(c), int(0));

  V<tuple<int, int, int>> ab;
  rep(i, n) ab.eb(a[i], c[i], i);

  multiset<pair<int, int>> constants;
  constants.insert({0, a[0] + c[0]});

  low_priority_queue<Event> que;
  que.push({a[0] + c[0], -1, 0});
  rep(i, n) que.push({a[i], c[i], -1});
  int linear = big;
  while (!que.empty()) {
    auto [x, c, constant] = que.top();
    que.pop();
    if (constant == -1) {
      int dp = linear + x;
      if (!constants.empty()) {
        chmin(dp, constants.begin()->first);
      }
      if (x == max_a) {
        wt(dp + sum_c);
        return;
      }
      constants.insert({dp, x + c});
      que.push({x + c, -1, dp});
    } else {
      int y = constant - x;
      chmin(linear, y);
      constants.erase(constants.find({constant, x}));
    }
  }
}

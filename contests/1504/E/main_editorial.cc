#include <bits/stdc++.h>

#include "codeforces.h"

void Main() {
  ints(n);
  V<pair<int, int>> v(n);
  cin >> v;
  sort(all(v));
  V<int> a(n), c(n);
  rep(i, n) tie(a[i], c[i]) = v[i];

  V<int> dist(n, big);
  dist[0] = 0;
  low_priority_queue<pair<int, int>> que;
  que.push({0, 0});

  while (!que.empty()) {
    auto [d, i] = que.top();
    que.pop();
    {
      auto it = lower_bound(all(a), a[i] + c[i] + 1);
      if (it != a.begin()) {
        // Cost 0
        int j = prev(it) - a.begin();
        if (chmin(dist[j], d)) {
          que.push({d, j});
        }
      }
      if (it != a.end()) {
        // Cost non zero
        int j = it - a.begin();
        int nd = d + a[j] - (a[i] + c[i]);
        if (chmin(dist[j], nd)) {
          que.push({nd, j});
        }
      }
    }
    if (i > 0) {
      int j = i - 1;
      if (chmin(dist[j], d)) {
        que.push({d, j});
      }
    }
  }
  int sum_c = accumulate(all(c), int(0));
  wt(dist[n - 1] + sum_c);
}

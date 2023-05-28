#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "graph.h"

void Main() {
  ints(n);
  V<pair<int, int>> es;
  rep(n - 1) {
    ints(u, v);
    --u, --v;
    es.eb(u, v);
  }
  WeightedGraph<int> g(n);
  rep(i, n - 1) {
    auto [u, v] = es[i];
    g[u].eb(v, i);
    g[v].eb(u, i);
  }
  int ans = 0;
  Fix([&](auto rec, int node, int parent, int depth, int idx) -> void {
    chmax(ans, depth);
    each(child, cidx, g[node]) if (child != parent) {
      rec(child, node, depth + (cidx < idx), cidx);
    }
  })(0, -1, 0, big);
  wt(ans);
}

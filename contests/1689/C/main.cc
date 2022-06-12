#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph g(n);
  g.Read();
  V<int> sizes(n);
  Fix([&](auto rec, int node, int parent) -> void {
    sizes[node] = 1;
    each(child, g[node]) if (child != parent) {
      rec(child, node);
      sizes[node] += sizes[child];
    }
  })(0, -1);
  V<int> memo(n);
  V<bool> seen(n);
  wt(Fix([&](auto rec, int node, int parent) -> int {
    if (!seen[node]) {
      seen[node] = true;
      V<int> cs;
      each(child, g[node]) if (child != parent) cs.eb(child);
      if (sz(cs) == 0) {
        memo[node] = 0;
      } else if (sz(cs) == 1) {
        memo[node] = sizes[cs[0]] - 1;
      } else {
        memo[node] = max(rec(cs[0], node) + sizes[cs[1]] - 1,
                         rec(cs[1], node) + sizes[cs[0]] - 1);
      }
    }
    return memo[node];
  })(0, -1));
}

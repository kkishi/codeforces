#include <bits/stdc++.h>

#include "codeforces.h"
#include "graph.h"

void Main() {
  ints(n);
  WeightedGraph<int> g(n);
  g.Read();

  using M = map<int, int>;
  struct Result {
    // Number of nodes in the subtree.
    int size;
    // Number of nodes in the subtree that can *not* be reached without passing
    // through the edges with the color.
    M unreachable;
    // Sum of the size of the connected components that are yet to be reflected
    // to the final result (because we know the size of the connected component
    // on the bottom side, but no the top side yet). They all share the same top
    // side connected component, so once we find the edge with the color, they
    // can be resolved altogether.
    M pending;
  };
  auto merge = [&](M& a, M& b) {
    if (sz(a) < sz(b)) swap(a, b);
    each(k, v, b) a[k] += v;
  };
  int ans = 0;
  auto reachable = [&](Result& r, int c) { return r.size - r.unreachable[c]; };
  Fix([&](auto rec, int node, int parent, int edge_color) -> Result {
    Result ret;
    ret.size = 1;
    each(child, color, g[node]) if (child != parent) {
      Result res = rec(child, node, color);
      ret.size += res.size;
      merge(ret.unreachable, res.unreachable);
      merge(ret.pending, res.pending);
    }
    if (parent == -1) {
      rep(i, 1, n + 1) ans += reachable(ret, i) * ret.pending[i];
    }
    if (edge_color != -ans) {
      ans += reachable(ret, edge_color) * ret.pending[edge_color];
      ret.pending[edge_color] = reachable(ret, edge_color);
      ret.unreachable[edge_color] = ret.size;
    }
    return ret;
  })(0, -1, -1);
  wt(ans);
}

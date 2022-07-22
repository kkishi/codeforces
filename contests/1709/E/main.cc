#include <bits/stdc++.h>

#include "codeforces.h"
#include "graph.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  Graph g(n);
  g.Read();
  int ans = 0;
  Fix([&](auto rec, int node, int parent) -> set<int> {
    set<int> st;
    st.insert(0);
    bool ok = true;
    each(child, g[node]) if (child != parent) {
      set<int> ST = rec(child, node);
      if (sz(st) < sz(ST)) swap(st, ST);
      each(e, ST) if (st.count(e ^ a[node])) ok = false;
      each(e, ST) st.insert(e);
    }
    if (!ok) {
      ++ans;
      return {};
    }
    set<int> ret;
    each(e, st) ret.insert(e ^ a[node]);
    return ret;
  })(0, -1);
  wt(ans);
}

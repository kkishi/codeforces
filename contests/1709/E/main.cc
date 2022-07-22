#include <bits/stdc++.h>

#include "codeforces.h"
#include "graph.h"

class xor_set {
 public:
  void all_xor(int x) { x_ ^= x; }
  V<int> get() const {
    V<int> v;
    each(e, st_) v.eb(e ^ x_);
    return v;
  }
  int count(int v) const { return st_.count(v ^ x_); }
  void insert(int v) { st_.insert(v ^ x_); }
  int size() const { return st_.size(); }

 private:
  set<int> st_;
  int x_ = 0;
};

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  Graph g(n);
  g.Read();
  int ans = 0;
  Fix([&](auto rec, int node, int parent) -> xor_set {
    xor_set st;
    st.insert(0);
    bool ok = true;
    each(child, g[node]) if (child != parent) {
      xor_set ST = rec(child, node);
      if (sz(st) < sz(ST)) swap(st, ST);
      V<int> v = ST.get();
      each(e, v) if (st.count(e ^ a[node])) ok = false;
      each(e, v) st.insert(e);
    }
    if (!ok) {
      ++ans;
      return {};
    }
    st.all_xor(a[node]);
    return st;
  })(0, -1);
  wt(ans);
}

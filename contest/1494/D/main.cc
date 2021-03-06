#include <bits/stdc++.h>

#include "codeforces.h"
#include "disjoint_set.h"

void Main() {
  ints(n);
  vector a(n, vector(n, int(0)));
  cin >> a;
  int N = n * 2 - 1;
  V<int> saraly(N);
  rep(i, n) saraly[i] = a[i][i];
  DisjointSet ds(n);
  V<tuple<int, int, int>> v;
  rep(i, n) rep(j, i + 1, n) v.eb(a[i][j], i, j);
  sort(all(v));
  int idx = n;
  V<int> parent(N, -1);
  V<int> repre(n);
  iota(all(repre), 0);
  for (auto [s, i, j] : v) {
    dbg(s, i, j);
    dbg(parent);
    dbg(repre);
    if (ds.Same(i, j)) {
      int r = repre[ds.Find(i)];
      assert(s == saraly[r]);
    } else {
      int ri = repre[ds.Find(i)];
      int rj = repre[ds.Find(j)];
      dbg(ri, rj);
      if (saraly[ri] > saraly[rj]) {
        swap(i, j);
        swap(ri, rj);
      }
      // assert(s > max(saraly[ri], saraly[rj]));
      if (saraly[rj] == s) {
        parent[ri] = rj;
        ds.Union(i, j);
        repre[ds.Find(i)] = rj;
        continue;
      }
      int k = idx;
      ++idx;
      saraly[k] = s;
      parent[ri] = k;
      parent[rj] = k;
      ds.Union(i, j);
      repre[ds.Find(i)] = k;
    }
  }
  wt(idx);
  // wt(saraly);
  rep(i, idx) {
    if (i) cout << " ";
    cout << saraly[i];
  }
  cout << endl;
  // rep(i, N) if (parent[i] == -1) wt(i + 1);
  wt(idx);
  // wt(N - 1);
  // rep(i, N) if (parent[i] != -1) wt(i + 1, parent[i] + 1);
  rep(i, idx - 1) wt(i + 1, parent[i] + 1);
}

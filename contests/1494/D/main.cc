#include <bits/stdc++.h>

#include "codeforces.h"
#include "disjoint_set.h"

void Main() {
  ints(n);
  vector a(n, vector(n, int(0)));
  cin >> a;
  int N = n * 2 - 1;
  V<int> salary(N);
  rep(i, n) salary[i] = a[i][i];
  DisjointSet ds(n);
  V<tuple<int, int, int>> v;
  rep(i, n) rep(j, i + 1, n) v.eb(a[i][j], i, j);
  sort(all(v));
  int idx = n;
  V<int> parent(N, -1);
  V<int> repre(n);
  iota(all(repre), 0);
  for (auto [s, i, j] : v) {
    if (ds.Same(i, j)) {
      int r = repre[ds.Find(i)];
      assert(s == salary[r]);
    } else {
      int ri = repre[ds.Find(i)];
      int rj = repre[ds.Find(j)];
      if (salary[ri] > salary[rj]) {
        swap(i, j);
        swap(ri, rj);
      }
      if (salary[rj] == s) {
        parent[ri] = rj;
        ds.Union(i, j);
        repre[ds.Find(i)] = rj;
        continue;
      }
      int k = idx;
      ++idx;
      salary[k] = s;
      parent[ri] = k;
      parent[rj] = k;
      ds.Union(i, j);
      repre[ds.Find(i)] = k;
    }
  }
  wt(idx);
  rep(i, idx) {
    if (i) cout << " ";
    cout << salary[i];
  }
  cout << endl;
  wt(idx);
  rep(i, idx - 1) wt(i + 1, parent[i] + 1);
}

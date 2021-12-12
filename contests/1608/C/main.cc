#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "disjoint_set.h"
#include "graph.h"
#include "strongly_connected_component.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;

  Graph<int> g(n);

  V<pair<int, int>> A;
  rep(i, n) A.eb(a[i], i);
  sort(all(A), greater{});
  rep(i, n - 1) g.AddEdge(A[i].second, A[i + 1].second);

  V<pair<int, int>> B;
  rep(i, n) B.eb(b[i], i);
  sort(all(B), greater{});
  rep(i, n - 1) g.AddEdge(B[i].second, B[i + 1].second);

  VV<int> scc = StronglyConnectedComponents(g);

  DisjointSet ds(n);
  each(e, scc) rep(i, 1, sz(e)) ds.Union(e[0], e[i]);

  map<int, int> S;
  each(e, scc) S[ds.Find(e[0])] = ds.Size(e[0]);

  reverse(all(scc));
  each(e, scc) {
    int x = ds.Find(e[0]);
    set<int> seen;
    seen.insert(x);
    each(f, e) {
      each(ed, g.Edges(f)) {
        int y = ds.Find(ed.to);
        if (seen.count(y)) continue;
        seen.insert(y);
        S[x] += S[y];
      }
    }
  }
  rep(i, n) cout << (S[ds.Find(i)] == n ? 1 : 0);
  cout << endl;
}

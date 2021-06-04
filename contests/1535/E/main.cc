#include <bits/stdc++.h>

#include "binary_search.h"
#include "codeforces_interactive.h"

void Main() {
  ints(q, a0, c0);
  V<int> A(q), C(q);
  A[0] = a0;
  C[0] = c0;
  VV<int> parent(q);
  V<int> depth(q);
  rep(i, q) {
    auto getp = [&](int i, int x) {
      for (int j = 0; (1 << j) <= x; ++j) {
        if (hasbit(x, j)) {
          i = parent[i][j];
        }
      }
      return i;
    };
    ints(t);
    if (t == 1) {
      ints(p, a, c);
      int v = i + 1;
      depth[v] = depth[p] + 1;
      for (int j = 1; j <= depth[v]; j <<= 1) {
        parent[v].pb(getp(p, j - 1));
      }
      A[v] = a;
      C[v] = c;
    } else {
      ints(v, w);
      int W = 0;
      int Cos = 0;
      while (W < w) {
        int x = v;
        for (int j = 20; j >= 0; --j) {
          if ((1 << j) <= depth[x] && A[parent[x][j]] > 0) {
            x = parent[x][j];
          }
        }
        if (A[x] == 0) break;
        int y = min(A[x], w - W);
        A[x] -= y;
        W += y;
        Cos += C[x] * y;
      }
      wt_flush(W, Cos);
    }
  }
}

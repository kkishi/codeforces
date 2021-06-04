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
        int y = 1 << j;
        if (x & y) {
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
      for (int j = 1, k = 0; j <= depth[v]; j *= 2, ++k) {
        parent[v].pb(getp(p, j - 1));
      }
      A[v] = a;
      C[v] = c;
    } else {
      ints(v, w);
      int W = 0;
      int Cos = 0;
      while (W < w) {
        int x = BinarySearch<int>(0, depth[v] + 1, [&](int x) {
          int p = getp(v, x);
          return A[p] > 0;
        });
        int X = getp(v, x);
        if (A[X] == 0) break;
        int y = min(A[X], w - W);
        A[X] -= y;
        W += y;
        Cos += C[X] * y;
      }
      wt_flush(W, Cos);
    }
  }
}

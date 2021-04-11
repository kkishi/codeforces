#include <bits/stdc++.h>

#include "codeforces.h"
#include "matrix.h"
#include "modint.h"

using mint = ModInt<>;

using M = Matrix<mint, 10, 10>;
using N = Matrix<mint, 10, 1>;

void Main() {
  V<M> p(200001);
  M mat;
  rep(i, 10) rep(j, 10) mat[0][0] = 0;
  rep(i, 9) mat[i + 1][i] = 1;
  mat[0][9] = 1;
  mat[1][9] = 1;
  p[1] = mat;
  rep(i, 1, sz(p) - 1) p[i + 1] = Mult(p[i], mat);

  ints(t);
  rep(t) {
    ints(n, m);
    N nat;
    rep(i, 10) nat[i][0] = 0;
    while (n) {
      ++nat[n % 10][0];
      n /= 10;
    }
    auto ans = Mult(p[m], nat);
    mint tot = 0;
    rep(i, 10) tot += ans[i][0];
    wt(tot);
  }
}

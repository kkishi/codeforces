#include <bits/stdc++.h>

#include "codeforces_interactive.h"

pair<int, int> Guess(int n, int i, int j) {
  auto q = [](int i, int j, int x) -> int {
    cout << "? 2 ";
    wt_flush(i + 1, j + 1, x);
    ints(r);
    assert(r != -1);
    return r;
  };
  auto Q = [&n](int i, int j) -> int {
    cout << "? 1 ";
    wt_flush(i + 1, j + 1, n - 1);
    ints(r);
    assert(r != -1);
    return r;
  };
  int r = q(i, j, 1);
  if (r == 1) {
    // A = 1, B >= 2
    int r2 = Q(i, j);
    return {1, r2};
  }
  // Check if B == 1
  if (r == 2) {
    int r2 = q(j, i, 1);
    if (r2 == 1) {
      int r3 = Q(j, i);
      return {r3, 1};
    }
  }
  // min(A, B) = r
  int r2 = q(i, j, r);
  if (r2 == r) {
    // A = r, B >= r
    int r3 = Q(i, j);
    return {r, r3};
  } else {
    // A >= r, B = r
    int r3 = Q(j, i);
    return {r3, r};
  }
}

void Solve() {
  ints(n);
  V<int> ans(n);
  for (int i = 0; i + 1 < n; i += 2) {
    auto [a, b] = Guess(n, i, i + 1);
    dbg(i, a, b);
    ans[i] = a;
    ans[i + 1] = b;
  }
  if (!even(n)) {
    auto [a, b] = Guess(n, n - 2, n - 1);
    dbg(a, b);
    ans[n - 2] = a;
    ans[n - 1] = b;
  }
  dbg(ans);
  cout << "! ";
  wt_flush(ans);
}

void Main() {
  ints(t);
  rep(t) Solve();
}

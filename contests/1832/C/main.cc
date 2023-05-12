#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "run_length_queue.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  RunLengthQueue q;
  rep(i, n - 1) {
    int d = a[i + 1] - a[i];
    if (d != 0) q.PushBack(d > 0 ? 1 : -1, 1);
  }
  wt(sz(q) + 1);
}

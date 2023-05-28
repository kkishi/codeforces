#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "run_length_queue.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  RunLengthQueue qa, qb;
  each(e, a) qa.PushBack(e, 1);
  each(e, b) qb.PushBack(e, 1);
  map<int, int> ma;
  each(k, v, qa) chmax(ma[k], v);
  int ans = 0;
  each(k, v, ma) chmax(ans, v);
  each(k, v, qb) chmax(ans, ma[k] + v);
  wt(ans);
}

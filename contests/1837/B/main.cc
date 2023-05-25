#include <bits/stdc++.h>

#include "codeforces_multi.h"
#include "run_length_queue.h"

void Main() {
  ints(n);
  strings(s);
  RunLengthQueue que;
  each(e, s) que.PushBack(e, 1);
  int ans = -big;
  each(_, e, que) chmax(ans, e + 1);
  wt(ans);
}

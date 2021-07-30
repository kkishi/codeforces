#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(W, H, x1, y1, x2, y2, w, h);
  auto solve = [](int W, int H, int w, int h, int x1, int y1, int x2,
                  int y2) -> int {
    dbg(x1, y1, x2, y2);
    if (x1 >= w) return 0;
    if (y1 >= h) return 0;
    int x = x2 - x1;
    int y = y2 - y1;
    int ret = big;
    if (x + w <= W) chmin(ret, w - x1);
    if (y + h <= H) chmin(ret, h - y1);
    return ret;
  };
  int ans = min({solve(W, H, w, h, x1, y1, x2, y2),
                 solve(W, H, w, h, W - x2, H - y2, W - x1, H - y1),
                 solve(H, W, h, w, y1, x1, y2, x2),
                 solve(H, W, h, w, H - y2, W - x2, H - y1, W - x1)});
  if (ans == big) {
    wt(-1);
  } else {
    wt(ans);
  }
}

#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(r, b, d);
  if (r > b) swap(r, b);
  wt(div_ceil(b, r) - 1 <= d);
}

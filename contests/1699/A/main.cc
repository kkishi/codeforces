#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  if (even(n)) {
    wt(n / 2, n / 2, 0);
  } else {
    wt(-1);
  }
}

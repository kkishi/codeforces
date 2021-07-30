#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(n);
  if (n <= 6) {
    wt(15);
  } else {
    if (!even(n)) ++n;
    wt(n / 2 * 5);
  }
}

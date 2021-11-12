#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(a, b, c);
  wt(abs(b * 2 - (a + c)) % 3 == 0 ? 0 : 1);
}

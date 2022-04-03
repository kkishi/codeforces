#include <bits/stdc++.h>

#include "codeforces_multi.h"

void Main() {
  ints(k);
  int p = k;
  int q = 100;
  int g = gcd(k, 100);
  p /= g;
  q /= g;
  int e = p;
  int w = q - e;
  wt(e + w);
}
